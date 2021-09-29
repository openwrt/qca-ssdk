#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/pinctrl/pinconf.h>
#include <linux/pinctrl/pinconf-generic.h>
#include <linux/pinctrl/pinctrl.h>
#include <linux/pinctrl/pinmux.h>
#include <linux/platform_device.h>
#include <linux/export.h>                                              
#include <linux/property.h>                                                     
#include <linux/interrupt.h>
#include <./../drivers/pinctrl/core.h>
#include <./../drivers/pinctrl/pinctrl-utils.h>
#include <linux/gpio/driver.h>
#include <asm/gpio.h>
//#include <linux/pinctrl/machine.h>

#define CONFIG_MHT

#ifdef CONFIG_MHT
#include "hsl/mht/mht_pinctrl.h"
#endif

#define PINCTRL_SUPPORT_MAPPINGS_UNREGISTER

struct hsl_pin_group {
	const char *name;
	const unsigned int *pins;
	const unsigned int num_pins;
	const unsigned int *funcs;
};

/*
194 struct group_desc {
195 	const char *name;
196 	int *pins;
197 	int num_pins;
198 	void *data;
199 };
*/

struct hsl_pin_function {
	const char *name;
	const char * const *groups;
	const unsigned int num_groups;
};

/*
130 struct function_desc {
131 	const char *name;
132 	const char **group_names;
133 	int num_group_names;
134 	void *data;
135 };
*/

struct hsl_pinctrl_ops_t {
	int (*gpio_set_bit)(unsigned int pin, int value);
	int (*gpio_get_bit)(unsigned int pin);

	int (*gpio_pin_func_sel)(unsigned int pin, unsigned int func);
	int (*gpio_pin_cfg_set_bias)(unsigned int pin, int bias);
	int (*gpio_pin_cfg_get_bias)(unsigned int pin);
	int (*gpio_pin_cfg_set_drvs)(unsigned int pin, int drvs);
	int (*gpio_pin_cfg_get_drvs)(unsigned int pin);
	int (*gpio_pin_cfg_set_oe)(unsigned int pin, bool oe);
	bool (*gpio_pin_cfg_get_oe)(unsigned int pin);

	void (*gpio_irq_enable)(unsigned int pin);
	void (*gpio_irq_disable)(unsigned int pin);	
	int (*gpio_irq_set_type)(unsigned int pin, unsigned int type);
	void (*gpio_irq_ack)(unsigned int pin);	
	int (*gpio_irq_status)(unsigned int pin);
} ;

struct hsl_pinctrl {
	struct pinctrl_dev *pctldev;
	struct device *dev;

	/* groups information */
	const struct hsl_pin_group *groups;
	unsigned int num_groups;

	/* function information */
	const struct hsl_pin_function *functions;
	unsigned int num_functions;

	struct pinctrl_pin_desc *pin_desc;
	unsigned int num_pins;

	const struct pinctrl_map *pin_map;
	unsigned int num_map;
	
 	struct pinctrl_gpio_range *gpioranges;
 	int ngpioranges;

	struct gpio_chip gpio_chip;
	raw_spinlock_t lock;

	struct hsl_pinctrl_ops_t ops;
};

#define HSL_GPIO_RANGE(_name, _id, _pinbase, _npins)	\
{							\
	.name = _name,				\
	.id = _id,					\
	.pin_base = _pinbase,				\
	.npins = _npins,				\
}

#define HSL_PIN_GROUP(group_name)	\
{							\
	.name = __stringify(group_name) "_grp",		\
	.pins = group_name ## _pins,			\
	.num_pins = ARRAY_SIZE(group_name ## _pins),	\
	.funcs = group_name ## _funcs, \
}

#define HSL_PIN_FUNCTION(func)				\
{							\
	.name = #func,				\
	.groups = func ## _grps,			\
	.num_groups = ARRAY_SIZE(func ## _grps),	\
}

int hsl_gpiolib_register(struct platform_device *pdev);
int hsl_gpiolib_unregister(struct platform_device *pdev);
struct hsl_pinctrl *hsl_pinctrl_init (void);
void hsl_pinctrl_exit (void);

