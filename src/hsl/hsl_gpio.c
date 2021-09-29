#include "hsl/hsl_pinctrl.h"
//https://opengrok.qualcomm.com/source/xref/kernel_msm-5.4/kernel/drivers/pinctrl/bcm/pinctrl-bcm2835.c
//https://opengrok.qualcomm.com/source/xref/kernel_msm-5.4/kernel/drivers/pinctrl/samsung/pinctrl-samsung.c#923
//https://opengrok.qualcomm.com/source/xref/kernel_msm-5.4/kernel/drivers/gpio/gpio-ath79.c#ath79_gpio_irq_handler

/****************************************************************************
 *
 * 1) Define GPIO Operations
 *
 ****************************************************************************/
static void _gpio_set(struct gpio_chip *gc, unsigned offset, int val)
{
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;

	ops->gpio_set_bit(offset, val);
}
static int _gpio_get(struct gpio_chip *gc, unsigned offset)
{
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;

	return ops->gpio_get_bit(offset);;
}

static int _gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
	return pinctrl_gpio_direction_input(gc->base + offset);
}

static int _gpio_direction_output(struct gpio_chip *gc, 
	unsigned offset, int val)
{
	_gpio_set(gc, offset, val);

	//jump to pinmux_gpio_set_direction
	return pinctrl_gpio_direction_output(gc->base + offset);
}

static int _gpio_get_direction(struct gpio_chip *gc, 
		unsigned int offset)
{
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct pinctrl_dev *pctldev = pinctrl->pctldev;
	const struct pinconf_ops *ops = pctldev->desc->confops;
	unsigned long config = PIN_CONFIG_INPUT_ENABLE;
		   
	ops->pin_config_get(pctldev, offset, &config);	
	
	printk("[%s] offset:%d dir:%d\n", __func__, offset, pinconf_to_config_argument(config));
	return pinconf_to_config_argument(config);
}

static struct gpio_chip gpio_chip = {
	.owner = THIS_MODULE,
	.request = gpiochip_generic_request,
	.free = gpiochip_generic_free,
	.direction_input = _gpio_direction_input,
	.direction_output = _gpio_direction_output,
	.get_direction = _gpio_get_direction,
	.get = _gpio_get,
	.set = _gpio_set,
	.set_config = gpiochip_generic_config,
	.base = -1,
	.ngpio = HSL_NGPIOS_MAX,
	.can_sleep = false,
};

/****************************************************************************
 *
 * 2) Define GPIO IRQ Operations
 *
 ****************************************************************************/
#ifdef HSL_GPIO_IRQ
static void _gpio_irq_enable(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	unsigned int gpio = irqd_to_hwirq(d);

	ops->gpio_irq_enable(gpio);
}

static void _gpio_irq_disable(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	unsigned int gpio = irqd_to_hwirq(d);	

	ops->gpio_irq_disable(gpio);
}

static int _gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	unsigned int gpio = irqd_to_hwirq(d);	

	return ops->gpio_irq_set_type(gpio, type);
}

static void _gpio_irq_ack(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	unsigned int gpio = irqd_to_hwirq(d);	

	ops->gpio_irq_ack(gpio);
}

static struct irq_chip gpio_irq_chip = {
	//.name = MODULE_NAME,
	.irq_enable = _gpio_irq_enable,
	.irq_disable = _gpio_irq_disable,
	.irq_set_type = _gpio_irq_set_type,
	.irq_ack = _gpio_irq_ack,
	.irq_mask = _gpio_irq_disable,
	.irq_unmask = _gpio_irq_enable,
};

static void _gpio_irq_handler(struct irq_desc *desc)
{
	struct gpio_chip *gc = irq_desc_get_handler_data(desc);
	struct hsl_pinctrl *pinctrl = gpiochip_get_data(gc);
	struct irq_chip *irqchip = irq_desc_get_chip(desc);	
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;
	int offset;

	chained_irq_enter(irqchip, desc);

	for (offset = 0; offset < gc->ngpio; offset++) {
		if(ops->gpio_irq_status(offset)) {
			ops->gpio_irq_ack(offset);
			//generic_handle_irq(irq_find_mapping(gc->irq.domain, offset));
		}
	}

	chained_irq_exit(irqchip, desc);	
}
#endif

/****************************************************************************
 *
 * 3) Register/Unregister GPIO Driver 
 *
 ****************************************************************************/
int hsl_gpiolib_register(struct platform_device *pdev)
{
	struct hsl_pinctrl *pinctrl = platform_get_drvdata(pdev);
	int ret;
	int n;

	pinctrl->gpio_chip = gpio_chip;
	pinctrl->gpio_chip.parent = pinctrl->dev;
	pinctrl->gpio_chip.label = dev_name(pinctrl->dev);

#ifdef HSL_GPIO_IRQ
	struct gpio_irq_chip *girq;
	girq = &pinctrl->gpio_chip.irq;
	girq->chip = &gpio_irq_chip;
	girq->chip->name = dev_name(pinctrl->dev);
	girq->parent_handler = _gpio_irq_handler;
	girq->num_parents = 1;
	girq->parents = devm_kcalloc(&pdev->dev, 1, sizeof(*girq->parents), GFP_KERNEL);
	if (!girq->parents)
		return -ENOMEM;
	girq->parents[0] = platform_get_irq(pdev, 0);//29;
	girq->default_type = IRQ_TYPE_NONE;
	girq->handler = handle_bad_irq;//handle_simple_irq;
#endif
	//ret = devm_gpiochip_add_data(pinctrl->dev, &pinctrl->gpio_chip, pinctrl);
	ret = gpiochip_add_data(&pinctrl->gpio_chip, pinctrl);
	if (ret < 0) {
		dev_err(pinctrl->dev, "unable to add GPIO chip\n");
		return ret;
	}

 	/* register gpio ranges */
 	for (n = 0; n < pinctrl->ngpioranges; n++) {
		pinctrl->gpioranges[n].gc = &gpio_chip;
		pinctrl->gpioranges[n].base = pinctrl->gpio_chip.base + pinctrl->gpioranges[n].pin_base;		
		//pinctrl->gpioranges[n].npins = pinctrl->gpio_chip.ngpio;
 		pinctrl_add_gpio_range(pinctrl->pctldev, &pinctrl->gpioranges[n]);
	}	
	printk("gpiochip_add_data with IRQ successfully!\n");

	return 0;
}

int hsl_gpiolib_unregister(struct platform_device *pdev)
{
	struct hsl_pinctrl *pinctrl = platform_get_drvdata(pdev);

	gpiochip_remove(&pinctrl->gpio_chip);

	return 0;
}

