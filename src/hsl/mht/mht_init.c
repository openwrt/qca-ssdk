#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>
#include "hsl/hsl_pinctrl.h"




void gpio_test(int gpio)
{
	printk("-------------------gpio_test---------------------\n");
	
	pinctrl_gpio_request(gpio);
	pinctrl_gpio_set_config(gpio, PIN_CONFIG_BIAS_PULL_UP);
	
	pinctrl_gpio_direction_input(gpio);
	printk("gpio_get_value(%d)=%x", gpio, gpio_get_value(gpio));

	pinctrl_gpio_direction_output(gpio);
	
	gpio_set_value(gpio, 1);
	printk("gpio_get_value(%d)=%x", gpio, gpio_get_value(gpio));

	gpio_set_value(gpio, 0);
	printk("gpio_get_value(%d)=%x", gpio, gpio_get_value(gpio));
	
	pinctrl_gpio_free(gpio);

	printk("----------------------------------------\n");

}


int pinctrl_module_init (void)
{
	struct hsl_pinctrl *pinctrl = hsl_pinctrl_init();
	int gpio_base = pinctrl->gpio_chip.base;

	gpio_test(gpio_base+21);	

	return 0;
}

void pinctrl_module_exit (void)
{
	hsl_pinctrl_exit();
	
	return;
}

/*
module_init (pinctrl_module_init);
module_exit (pinctrl_module_exit);
MODULE_LICENSE("GPL");
*/

