#include "hsl/hsl_pinctrl.h"

/****************************************************************************
 *
 * 1) Define groups & pinctrl operations
 *
 ****************************************************************************/
static int _get_groups_count(struct pinctrl_dev *pctldev)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);

	return pinctrl->num_groups;
}

static const char *_get_group_name(struct pinctrl_dev *pctldev,
				      unsigned int selector)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);

	return pinctrl->groups[selector].name;
}

static int _get_group_pins(struct pinctrl_dev *pctldev,
			      unsigned int selector, const unsigned int **pins,
			      unsigned int *num_pins)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);

	*pins = pinctrl->groups[selector].pins;
	*num_pins = pinctrl->groups[selector].num_pins;

	return 0;
}

static void _pin_dbg_show(struct pinctrl_dev *pctldev,
			     struct seq_file *s, unsigned int offset)
{
	seq_printf(s, " %s", dev_name(pctldev->dev));
}

static const struct pinctrl_ops pinctrl_ops = {
	.get_groups_count = _get_groups_count,
	.get_group_name = _get_group_name,
	.get_group_pins = _get_group_pins,
	.pin_dbg_show = _pin_dbg_show,
	.dt_node_to_map = pinconf_generic_dt_node_to_map_pin,
	.dt_free_map = pinctrl_utils_free_map,
};

/****************************************************************************
 *
 * 2) Define functions & pinmux operations
 *
 ****************************************************************************/
static int _get_functions_count(struct pinctrl_dev *pctldev)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);

	return pinctrl->num_functions;
}

static const char *_get_function_name(struct pinctrl_dev *pctldev,
					 unsigned int selector)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);

	return pinctrl->functions[selector].name;
}

static int _get_function_groups(struct pinctrl_dev *pctldev,
				   unsigned int selector,
				   const char * const **groups,
				   unsigned int * const num_groups)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);

	*groups = pinctrl->functions[selector].groups;
	*num_groups = pinctrl->functions[selector].num_groups;

	return 0;
}

static int _set_mux(struct pinctrl_dev *pctldev,
			     unsigned int func_sel, unsigned int grp_sel)
{
	int i, ret;
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	const struct hsl_pin_function *func;
	const struct hsl_pin_group *grp;
	unsigned long flags;

	if (grp_sel > pinctrl->num_groups ||
		func_sel > pinctrl->num_functions)
		return -EINVAL;

	func = &pinctrl->functions[func_sel];
	grp = &pinctrl->groups[grp_sel];

	for (i = 0; i < grp->num_pins; i++) {
		raw_spin_lock_irqsave(&pinctrl->lock, flags);
		ret = ops->gpio_pin_func_sel(grp->pins[i], grp->funcs[i]);//func->value);
		raw_spin_unlock_irqrestore(&pinctrl->lock, flags);

		if (ret)
			return ret;
	}

	return 0;
}

static int _gpio_set_direction(struct pinctrl_dev *pctldev,
 	   struct pinctrl_gpio_range *range, unsigned offset, bool input)
{
	const struct pinconf_ops *ops = pctldev->desc->confops;
	unsigned long configs[] = { input? PIN_CONFIG_INPUT_ENABLE:PIN_CONFIG_OUTPUT_ENABLE };

	return ops->pin_config_set(pctldev, offset, configs, ARRAY_SIZE(configs));
}

static const struct pinmux_ops pinmux_ops = {
	.get_functions_count = _get_functions_count,
	.get_function_name = _get_function_name,
	.get_function_groups = _get_function_groups,
	.gpio_set_direction = _gpio_set_direction,	
	.set_mux = _set_mux,
};

/****************************************************************************
 *
 * 3) Define pins & pinconf operations
 *
 ****************************************************************************/
static int _pin_config_get(struct pinctrl_dev *pctldev, unsigned int pin,
			      unsigned long *config)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
	enum pin_config_param param = pinconf_to_config_param(*config);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	u16 arg;
	int bias, drvs, oe;

	switch (param) {
			case PIN_CONFIG_BIAS_BUS_HOLD:
			case PIN_CONFIG_BIAS_DISABLE:
			case PIN_CONFIG_BIAS_PULL_DOWN:
			case PIN_CONFIG_BIAS_PULL_UP:
				bias = ops->gpio_pin_cfg_get_bias(pin);
				arg = (param == bias)? 1: 0;
				break;			
			
			case PIN_CONFIG_DRIVE_STRENGTH:
				drvs = ops->gpio_pin_cfg_get_drvs(pin);
				arg = drvs;
				break;

			case PIN_CONFIG_OUTPUT:
				oe = ops->gpio_pin_cfg_get_oe(pin);
				if (oe == false)
					return -EINVAL;
				
				arg = ops->gpio_get_bit(pin);
				break;

			case PIN_CONFIG_INPUT_ENABLE:
				oe = ops->gpio_pin_cfg_get_oe(pin);
				arg = (oe == false)? 1: 0;
				break;

			case PIN_CONFIG_OUTPUT_ENABLE:
				oe = ops->gpio_pin_cfg_get_oe(pin);
				arg = (oe == true)? 1: 0;
				break;

		default:
			printk("%s doesn't support:%d\n", __func__, param);
			return -ENOTSUPP;
		}

	*config = pinconf_to_config_packed(param, arg);
	return 0;
}

static int _pin_config_set(struct pinctrl_dev *pctldev, unsigned int pin,
			      unsigned long *configs, unsigned int num_configs)
{
	struct hsl_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	enum pin_config_param param;
	unsigned int i;
	u32 arg;
	
	for (i = 0; i < num_configs; i++) {
		param = pinconf_to_config_param(configs[i]);
		arg = pinconf_to_config_argument(configs[i]);
		//printk("%s %d:%d\n", __func__, param, arg);
		switch (param) {
			case PIN_CONFIG_BIAS_BUS_HOLD:
			case PIN_CONFIG_BIAS_DISABLE:
			case PIN_CONFIG_BIAS_PULL_DOWN:
			case PIN_CONFIG_BIAS_PULL_UP:
				ops->gpio_pin_cfg_set_bias(pin, param);
				break;			
			
			case PIN_CONFIG_DRIVE_STRENGTH:
				ops->gpio_pin_cfg_set_drvs(pin, arg);
				break;

			case PIN_CONFIG_OUTPUT:
				ops->gpio_pin_cfg_set_oe(pin, true);
				ops->gpio_set_bit(pin, arg);
				break;

			case PIN_CONFIG_INPUT_ENABLE:
				ops->gpio_pin_cfg_set_oe(pin, false);
				break;

			case PIN_CONFIG_OUTPUT_ENABLE:
				ops->gpio_pin_cfg_set_oe(pin, true);
				break;

		default:
			printk("%s doesn't support:%d\n", __func__, param);
			return -ENOTSUPP;
		}
	}
	
	return 0; /* success */
}

static const struct pinconf_ops pinconf_ops = {
	.is_generic = true,
	.pin_config_get = _pin_config_get,
	.pin_config_set = _pin_config_set,
};

/****************************************************************************
 *
 * 4) Replace Kernel Pinctl Mapping To Support Module Load/Unload 
 *
 ****************************************************************************/
#ifdef PINCTRL_SUPPORT_MAPPINGS_UNREGISTER
static int _pinmux_func_name_to_selector(struct pinctrl_dev *pctldev,
					const char *function)
{
	const struct pinmux_ops *ops = pctldev->desc->pmxops;
	unsigned nfuncs = ops->get_functions_count(pctldev);
	unsigned selector = 0;

	/* See if this pctldev has this function */
	while (selector < nfuncs) {
		const char *fname = ops->get_function_name(pctldev, selector);

		if (!strcmp(function, fname))
			return selector;

		selector++;
	}

	return -EINVAL;
}

static int _pinctrl_get_group_selector(struct pinctrl_dev *pctldev,
			       const char *pin_group)
{
	const struct pinctrl_ops *pctlops = pctldev->desc->pctlops;
	unsigned ngroups = pctlops->get_groups_count(pctldev);
	unsigned group_selector = 0;

	while (group_selector < ngroups) {
		const char *gname = pctlops->get_group_name(pctldev,
							    group_selector);
		if (gname && !strcmp(gname, pin_group)) {
			dev_dbg(pctldev->dev,
				"found group selector %u for %s\n",
				group_selector,
				pin_group);
			return group_selector;
		}

		group_selector++;
	}

	dev_err(pctldev->dev, "does not have pin group %s\n",
		pin_group);

	return -EINVAL;
}

static int _pinmux_map_to_setting(const struct pinctrl_map *map,
			  struct pinctrl_setting *setting)
{
	struct pinctrl_dev *pctldev = setting->pctldev;
	const struct pinmux_ops *pmxops = pctldev->desc->pmxops;
	char const * const *groups;
	unsigned num_groups;
	int ret;
	const char *group;

	if (!pmxops) {
		printk("does not support mux function\n");
		return -EINVAL;
	}

	ret = _pinmux_func_name_to_selector(pctldev, map->data.mux.function);
	if (ret < 0) {
		printk("invalid function %s in map table\n",
			map->data.mux.function);
		return ret;
	}
	setting->data.mux.func = ret;

	ret = pmxops->get_function_groups(pctldev, setting->data.mux.func,
					  &groups, &num_groups);
	if (ret < 0) {
		printk("can't query groups for function %s\n",
			map->data.mux.function);
		return ret;
	}
	if (!num_groups) {
		printk("function %s can't be selected on any group\n",
			map->data.mux.function);
		return -EINVAL;
	}
	if (map->data.mux.group) {
		group = map->data.mux.group;
		ret = match_string(groups, num_groups, group);
		if (ret < 0) {
			printk("invalid group \"%s\" for function \"%s\"\n",
				group, map->data.mux.function);
			return ret;
		}
	} else {
		group = groups[0];
	}

	ret = _pinctrl_get_group_selector(pctldev, group);
	if (ret < 0) {
		printk("invalid group %s in map table\n",
			map->data.mux.group);
		return ret;
	}
	setting->data.mux.group = ret;

	return 0;
}

static int _pin_get_from_name(struct pinctrl_dev *pctldev, const char *name)
{
	unsigned i, pin;

	/* The pin number can be retrived from the pin controller descriptor */
	for (i = 0; i < pctldev->desc->npins; i++) {
		struct pin_desc *desc;

		pin = pctldev->desc->pins[i].number;
		desc = pin_desc_get(pctldev, pin);
		/* Pin space may be sparse */
		if (desc && !strcmp(name, desc->name))
			return pin;
	}

	return -EINVAL;
}

static int _pinconf_map_to_setting(const struct pinctrl_map *map,
			  struct pinctrl_setting *setting)

{
	struct pinctrl_dev *pctldev = setting->pctldev;
	int pin = _pin_get_from_name(pctldev,
				map->data.configs.group_or_pin);
	if (pin < 0) {
		dev_err(pctldev->dev, "could not map pin config for \"%s\"",
			map->data.configs.group_or_pin);
		return pin;
	}
	setting->data.configs.group_or_pin = pin;
	setting->data.configs.num_configs = map->data.configs.num_configs;
	setting->data.configs.configs = map->data.configs.configs;	

	return 0;
}

static int _pinctrl_register_mappings_pinmux_pincong(struct hsl_pinctrl *pinctrl)

{
	struct pinctrl_dev *pctldev = pinctrl->pctldev;
	const struct pinmux_ops *pinmux_ops = pctldev->desc->pmxops;
	const struct pinconf_ops *pinconf_ops = pctldev->desc->confops;
	int i=0;

	const struct pinctrl_map *pin_maps = pinctrl->pin_map;
	struct pinctrl_setting setting;
	unsigned int num_map = pinctrl->num_map;

	for(i=0;i<num_map;i++) {
		const struct pinctrl_map *pin_map = &pin_maps[i];
		memset(&setting, 0, sizeof(setting));
		setting.pctldev = pctldev;
		if (pin_map->type == PIN_MAP_TYPE_MUX_GROUP) {
			_pinmux_map_to_setting(pin_map, &setting);
			pinmux_ops->set_mux(pctldev, setting.data.mux.func, setting.data.mux.group);

		} else if (pin_map->type == PIN_MAP_TYPE_CONFIGS_PIN) {
			_pinconf_map_to_setting(pin_map, &setting);
			pinconf_ops->pin_config_set(pctldev,
 							setting.data.configs.group_or_pin,
 							setting.data.configs.configs,
 							setting.data.configs.num_configs);
		} 
	}

	return 0;
}
#endif

/****************************************************************************
 *
 * 5) Register Pinctrl Driver with Linux Pinctrl Subsystem 
 *
 ****************************************************************************/
static struct pinctrl_desc pinctrl_desc = {
	.name = "pinmux",
	.pctlops = &pinctrl_ops,
	.pmxops = &pinmux_ops,
	.confops = &pinconf_ops,
};

static int hsl_pinctrl_register(struct platform_device *pdev)
{
	struct hsl_pinctrl *pinctrl = platform_get_drvdata(pdev);
	int ret = 0;

	pinctrl_desc.pins = pinctrl->pin_desc;
	pinctrl_desc.npins = pinctrl->num_pins;

	raw_spin_lock_init(&pinctrl->lock);
	ret = pinctrl_register_and_init(&pinctrl_desc,
							&pdev->dev,
							 pinctrl,
							 &pinctrl->pctldev);
	if (ret) {
		printk( "Failed to pinctrl_register_and_init (%d)\n", ret);
		return ret;
	}

#ifdef PINCTRL_SUPPORT_MAPPINGS_UNREGISTER
	ret = _pinctrl_register_mappings_pinmux_pincong(pinctrl);
#else
	ret = pinctrl_register_mappings(pinctrl->pin_map, pinctrl->num_map);
#endif
	if (ret) {
		printk( "Failed to pinctrl_register_mappings (%d)\n", ret);
		return ret;
	}

	ret = pinctrl_enable(pinctrl->pctldev);
	if (ret) {
		printk( "Failed to enable pinctrl (%d)\n", ret);
		return ret;
	}

	//devm_pinctrl_get_select(&pdev->dev, PINCTRL_STATE_DEFAULT);
	return 0;
}

static int hsl_pinctrl_unregister(struct platform_device *pdev)
{
	struct hsl_pinctrl *pinctrl = platform_get_drvdata(pdev);
	pinctrl_unregister(pinctrl->pctldev);

	return 0;
}

/****************************************************************************
 *
 * 6) Pinctrl APIs
 *
 ****************************************************************************/
static void platform_release(struct device * dev)
{
    return ;
}

static struct platform_device pinctrl_pdev = {
 	//.name	= "pinctrl-mht",
 	.id	= -1,
 	.dev	= {
 		.platform_data	= NULL,
		.release = platform_release,
 	}
};

struct hsl_pinctrl *hsl_pinctrl_init (void)
{
	struct platform_device *pdev = &pinctrl_pdev;
	struct hsl_pinctrl *pinctrl;

	pinctrl = mht_pinctrl_init(pdev);
	platform_device_register(pdev);
	platform_set_drvdata(pdev, pinctrl);

	hsl_pinctrl_register(pdev);
	hsl_gpiolib_register(pdev);

	printk("***Hello pinctrl without dts***\n");

	return pinctrl;
}

void hsl_pinctrl_exit (void)
{
	struct platform_device *pdev = &pinctrl_pdev;

	hsl_gpiolib_unregister(pdev);
	hsl_pinctrl_unregister(pdev);
	platform_device_unregister(pdev);

	printk("***Bye pinctrl without dts***\n");
	
	return;
}

