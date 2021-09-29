#include "hsl/hsl_pinctrl.h"

/****************************************************************************
 *
 * 1) PINs Number Definition
 *
 ****************************************************************************/
/*GPIO*/
static const unsigned int gpio0_pins[] =  { 0 };
static const unsigned int gpio1_pins[] =  { 1 };
static const unsigned int gpio2_pins[] =  { 2 };
static const unsigned int gpio3_pins[] =  { 3 };
static const unsigned int gpio4_pins[] =  { 4 };
static const unsigned int gpio5_pins[] =  { 5 };
static const unsigned int gpio6_pins[] =  { 6 };
static const unsigned int gpio7_pins[] =  { 7 };
static const unsigned int gpio8_pins[] =  { 8 };
static const unsigned int gpio9_pins[] =  { 9 };
static const unsigned int gpio10_pins[] = { 10 };
static const unsigned int gpio11_pins[] = { 11 };
static const unsigned int gpio12_pins[] = { 12 };
static const unsigned int gpio13_pins[] = { 13 };
static const unsigned int gpio14_pins[] = { 14 };
static const unsigned int gpio15_pins[] = { 15 };
static const unsigned int gpio16_pins[] = { 16 };
static const unsigned int gpio17_pins[] = { 17 };
static const unsigned int gpio18_pins[] = { 18 };
static const unsigned int gpio19_pins[] = { 19 };
static const unsigned int gpio20_pins[] = { 20 };
static const unsigned int gpio21_pins[] = { 21 };

/*Minimum Concurrency Set Function*/
static const unsigned int intn_wol_pins[] = 		{ 0 };
static const unsigned int intn_pins[] = 			{ 1 };
static const unsigned int p0_led_0_pins[] = 		{ 2 };
static const unsigned int p1_led_0_pins[] = 		{ 3 };
static const unsigned int p2_led_0_pins[] = 		{ 4 };
static const unsigned int p3_led_0_pins[] = 		{ 5 };
static const unsigned int pps_in_pins[] = 			{ 6 };
static const unsigned int tod_in_pins[] = 			{ 7 };
static const unsigned int rtc_refclk_in_pins[] =	{ 8 };
static const unsigned int p0_pps_out_pins[] = 		{ 9 };
static const unsigned int p1_pps_out_pins[] = 		{ 10 };
static const unsigned int p2_pps_out_pins[] = 		{ 11 };
static const unsigned int p3_pps_out_pins[] = 		{ 12 };
static const unsigned int p0_tod_out_pins[] = 		{ 13 };
static const unsigned int p0_clk125_tdi_pins[] = 	{ 14 };
static const unsigned int p0_sync_clko_ptp_pins[] =	{ 15 };
static const unsigned int p0_led_1_pins[] = 		{ 16 };
static const unsigned int p1_led_1_pins[] = 		{ 17 };
static const unsigned int p2_led_1_pins[] = 		{ 18 };
static const unsigned int p3_led_1_pins[] = 		{ 19 };
static const unsigned int mdc_m_pins[] = 			{ 20 };
static const unsigned int mdo_m_pins[] = 			{ 21 };

/*Alt Function K*/
static const unsigned int event_trg_i_pins[] = 		{ 6 };
static const unsigned int p0_event_trg_o_pins[] = 	{ 9 };
static const unsigned int p1_event_trg_o_pins[] = 	{ 10 };
static const unsigned int p2_event_trg_o_pins[] = 	{ 11 };
static const unsigned int p3_event_trg_o_pins[] = 	{ 12 };
static const unsigned int p1_tod_out_pins[] = 		{ 13 };
static const unsigned int p1_clk125_tdi_pins[] = 	{ 14 };
static const unsigned int p1_sync_clko_ptp_pins[] = { 15 };
static const unsigned int p0_intn_wol_pins[] = 		{ 16 };
static const unsigned int p1_intn_wol_pins[] = 		{ 17 };
static const unsigned int p2_intn_wol_pins[] = 		{ 18 };
static const unsigned int p3_intn_wol_pins[] = 		{ 19 };

/*Alt Function L*/
static const unsigned int p2_tod_out_pins[] = 		{ 13 };
static const unsigned int p2_clk125_tdi_pins[] = 	{ 14 };
static const unsigned int p2_sync_clko_ptp_pins[] = { 15 };

/*Alt Function M*/
static const unsigned int p3_tod_out_pins[] = 		{ 13 };
static const unsigned int p3_clk125_tdi_pins[] = 	{ 14 };
static const unsigned int p3_sync_clko_ptp_pins[] = { 15 };

/*Alt Function N*/
static const unsigned int p0_led_2_pins[] = 		{ 6 };
static const unsigned int p1_led_2_pins[] = 		{ 7 };
static const unsigned int p2_led_2_pins[] = 		{ 8 };
static const unsigned int p3_led_2_pins[] = 		{ 9 };

/*Alt Function O*/
static const unsigned int jtag_tdo_pins[] = 		{ 5 };
static const unsigned int jtag_tck_pins[] = 		{ 6 };
static const unsigned int jtag_tdi_pins[] = 		{ 7 };
static const unsigned int jtag_tms_pins[] = 		{ 18 };
static const unsigned int jtag_trst_pins[] = 		{ 19 };

/*Alt Function Debug Bus Out*/
static const unsigned int dbg_out_clk_pins[] = 		{ 0 };
static const unsigned int dbg_bus_out0_pins[] = 	{ 1 };
static const unsigned int dbg_bus_out1_pins[] = 	{ 2 };
static const unsigned int dbg_bus_out12_pins[] = 	{ 3 };
static const unsigned int dbg_bus_out13_pins[] = 	{ 4 };
static const unsigned int dbg_bus_out2_pins[] = 	{ 8 };
static const unsigned int dbg_bus_out3_pins[] = 	{ 9 };
static const unsigned int dbg_bus_out4_pins[] = 	{ 10 };
static const unsigned int dbg_bus_out5_pins[] = 	{ 11 };
static const unsigned int dbg_bus_out6_pins[] = 	{ 12 };
static const unsigned int dbg_bus_out7_pins[] = 	{ 13 };
static const unsigned int dbg_bus_out8_pins[] = 	{ 14 };
static const unsigned int dbg_bus_out9_pins[] = 	{ 15 };
static const unsigned int dbg_bus_out10_pins[] = 	{ 16 };
static const unsigned int dbg_bus_out11_pins[] = 	{ 17 };
static const unsigned int dbg_bus_out14_pins[] = 	{ 20 };
static const unsigned int dbg_bus_out15_pins[] = 	{ 21 };


/****************************************************************************
 *
 *	2) PINs Functions Value Definition  GPIO_CFG[5:2] (FUNC_SEL)
 *
 ****************************************************************************/
/*GPIO*/
static const unsigned int gpio0_funcs[] =  { 0 };
static const unsigned int gpio1_funcs[] =  { 0 };
static const unsigned int gpio2_funcs[] =  { 0 };
static const unsigned int gpio3_funcs[] =  { 0 };
static const unsigned int gpio4_funcs[] =  { 0 };
static const unsigned int gpio5_funcs[] =  { 0 };
static const unsigned int gpio6_funcs[] =  { 0 };
static const unsigned int gpio7_funcs[] =  { 0 };
static const unsigned int gpio8_funcs[] =  { 0 };
static const unsigned int gpio9_funcs[] =  { 0 };
static const unsigned int gpio10_funcs[] = { 0 };
static const unsigned int gpio11_funcs[] = { 0 };
static const unsigned int gpio12_funcs[] = { 0 };
static const unsigned int gpio13_funcs[] = { 0 };
static const unsigned int gpio14_funcs[] = { 0 };
static const unsigned int gpio15_funcs[] = { 0 };
static const unsigned int gpio16_funcs[] = { 0 };
static const unsigned int gpio17_funcs[] = { 0 };
static const unsigned int gpio18_funcs[] = { 0 };
static const unsigned int gpio19_funcs[] = { 0 };
static const unsigned int gpio20_funcs[] = { 0 };
static const unsigned int gpio21_funcs[] = { 0 };

/*Minimum Concurrency Set Function*/
static const unsigned int intn_wol_funcs[] = 		{ 1 };
static const unsigned int intn_funcs[] = 			{ 1 };
static const unsigned int p0_led_0_funcs[] = 		{ 1 };
static const unsigned int p1_led_0_funcs[] = 		{ 1 };
static const unsigned int p2_led_0_funcs[] = 		{ 1 };
static const unsigned int p3_led_0_funcs[] = 		{ 1 };
static const unsigned int pps_in_funcs[] = 			{ 1 };
static const unsigned int tod_in_funcs[] = 			{ 1 };
static const unsigned int rtc_refclk_in_funcs[] =	{ 1 };
static const unsigned int p0_pps_out_funcs[] = 		{ 1 };
static const unsigned int p1_pps_out_funcs[] = 		{ 1 };
static const unsigned int p2_pps_out_funcs[] = 		{ 1 };
static const unsigned int p3_pps_out_funcs[] = 		{ 1 };
static const unsigned int p0_tod_out_funcs[] = 		{ 1 };
static const unsigned int p0_clk125_tdi_funcs[] = 	{ 1 };
static const unsigned int p0_sync_clko_ptp_funcs[] ={ 1 };
static const unsigned int p0_led_1_funcs[] = 		{ 1 };
static const unsigned int p1_led_1_funcs[] = 		{ 1 };
static const unsigned int p2_led_1_funcs[] = 		{ 1 };
static const unsigned int p3_led_1_funcs[] = 		{ 1 };
static const unsigned int mdc_m_funcs[] = 			{ 1 };
static const unsigned int mdo_m_funcs[] = 			{ 1 };

/*Alt Function K*/
static const unsigned int event_trg_i_funcs[] = 	{ 2 };
static const unsigned int p0_event_trg_o_funcs[] = 	{ 2 };
static const unsigned int p1_event_trg_o_funcs[] = 	{ 2 };
static const unsigned int p2_event_trg_o_funcs[] = 	{ 2 };
static const unsigned int p3_event_trg_o_funcs[] = 	{ 2 };
static const unsigned int p1_tod_out_funcs[] = 		{ 2 };
static const unsigned int p1_clk125_tdi_funcs[] = 	{ 2 };
static const unsigned int p1_sync_clko_ptp_funcs[] ={ 2 };
static const unsigned int p0_intn_wol_funcs[] = 	{ 2 };
static const unsigned int p1_intn_wol_funcs[] = 	{ 2 };
static const unsigned int p2_intn_wol_funcs[] = 	{ 2 };
static const unsigned int p3_intn_wol_funcs[] = 	{ 2 };

/*Alt Function L*/
static const unsigned int p2_tod_out_funcs[] = 		{ 3 };
static const unsigned int p2_clk125_tdi_funcs[] = 	{ 3 };
static const unsigned int p2_sync_clko_ptp_funcs[] ={ 3 };

/*Alt Function M*/
static const unsigned int p3_tod_out_funcs[] = 		{ 4 };
static const unsigned int p3_clk125_tdi_funcs[] = 	{ 4 };
static const unsigned int p3_sync_clko_ptp_funcs[] ={ 4 };

/*Alt Function N*/
static const unsigned int p0_led_2_funcs[] = 		{ 3 };
static const unsigned int p1_led_2_funcs[] = 		{ 2 };
static const unsigned int p2_led_2_funcs[] = 		{ 2 };
static const unsigned int p3_led_2_funcs[] = 		{ 3 };

/*Alt Function O*/
static const unsigned int jtag_tdo_funcs[] = 		{  };
static const unsigned int jtag_tck_funcs[] = 		{  };
static const unsigned int jtag_tdi_funcs[] = 		{  };
static const unsigned int jtag_tms_funcs[] = 		{  };
static const unsigned int jtag_trst_funcs[] = 		{  };

/*Alt Function Debug Bus Out*/
static const unsigned int dbg_out_clk_funcs[] = 	{ 2 };
static const unsigned int dbg_bus_out0_funcs[] = 	{ 2 };
static const unsigned int dbg_bus_out1_funcs[] = 	{ 2 };
static const unsigned int dbg_bus_out12_funcs[] = 	{ 2 };
static const unsigned int dbg_bus_out13_funcs[] = 	{ 2 };
static const unsigned int dbg_bus_out2_funcs[] = 	{ 3 };
static const unsigned int dbg_bus_out3_funcs[] = 	{ 4 };
static const unsigned int dbg_bus_out4_funcs[] = 	{ 3 };
static const unsigned int dbg_bus_out5_funcs[] = 	{ 3 };
static const unsigned int dbg_bus_out6_funcs[] = 	{ 3 };
static const unsigned int dbg_bus_out7_funcs[] = 	{ 5 };
static const unsigned int dbg_bus_out8_funcs[] = 	{ 5 };
static const unsigned int dbg_bus_out9_funcs[] = 	{ 5 };
static const unsigned int dbg_bus_out10_funcs[] = 	{ 3 };
static const unsigned int dbg_bus_out11_funcs[] = 	{ 3 };
static const unsigned int dbg_bus_out14_funcs[] = 	{ 2 };
static const unsigned int dbg_bus_out15_funcs[] = 	{ 2 };


/****************************************************************************
 *
 * 3) PINs Groups
 *
 ****************************************************************************/
static const struct hsl_pin_group pin_groups[] = {
	/*GPIO*/
	HSL_PIN_GROUP(gpio0),
	HSL_PIN_GROUP(gpio1),
	HSL_PIN_GROUP(gpio2),
	HSL_PIN_GROUP(gpio3),	
	HSL_PIN_GROUP(gpio4),
	HSL_PIN_GROUP(gpio5),
	HSL_PIN_GROUP(gpio6),
	HSL_PIN_GROUP(gpio7),
	HSL_PIN_GROUP(gpio8),
	HSL_PIN_GROUP(gpio9),	
	HSL_PIN_GROUP(gpio10),
	HSL_PIN_GROUP(gpio11),
	HSL_PIN_GROUP(gpio12),
	HSL_PIN_GROUP(gpio13),
	HSL_PIN_GROUP(gpio14),
	HSL_PIN_GROUP(gpio15),
	HSL_PIN_GROUP(gpio16),
	HSL_PIN_GROUP(gpio17),
	HSL_PIN_GROUP(gpio18),	
	HSL_PIN_GROUP(gpio19),
	HSL_PIN_GROUP(gpio20),
	HSL_PIN_GROUP(gpio21),

	/*Minimum Concurrency Set Function*/
	HSL_PIN_GROUP(intn_wol),
	HSL_PIN_GROUP(intn),	
	HSL_PIN_GROUP(p0_led_0),
	HSL_PIN_GROUP(p1_led_0),
	HSL_PIN_GROUP(p2_led_0),
	HSL_PIN_GROUP(p3_led_0),	
	HSL_PIN_GROUP(pps_in),
	HSL_PIN_GROUP(tod_in),
	HSL_PIN_GROUP(rtc_refclk_in),	
	HSL_PIN_GROUP(p0_pps_out),	
	HSL_PIN_GROUP(p1_pps_out),
	HSL_PIN_GROUP(p2_pps_out),
	HSL_PIN_GROUP(p3_pps_out),
	HSL_PIN_GROUP(p0_tod_out),
	HSL_PIN_GROUP(p0_clk125_tdi),
	HSL_PIN_GROUP(p0_sync_clko_ptp),	
	HSL_PIN_GROUP(p0_led_1),
	HSL_PIN_GROUP(p1_led_1),
	HSL_PIN_GROUP(p2_led_1),
	HSL_PIN_GROUP(p3_led_1),
	HSL_PIN_GROUP(mdc_m),
	HSL_PIN_GROUP(mdo_m),

	/*Alt Function K*/
	HSL_PIN_GROUP(event_trg_i),
	HSL_PIN_GROUP(p0_event_trg_o),
	HSL_PIN_GROUP(p1_event_trg_o),
	HSL_PIN_GROUP(p2_event_trg_o),
	HSL_PIN_GROUP(p3_event_trg_o),
	HSL_PIN_GROUP(p1_tod_out),
	HSL_PIN_GROUP(p1_clk125_tdi),
	HSL_PIN_GROUP(p1_sync_clko_ptp),
	HSL_PIN_GROUP(p0_intn_wol),
	HSL_PIN_GROUP(p1_intn_wol),
	HSL_PIN_GROUP(p2_intn_wol),
	HSL_PIN_GROUP(p3_intn_wol),

	/*Alt Function L*/
	HSL_PIN_GROUP(p2_tod_out),
	HSL_PIN_GROUP(p2_clk125_tdi),
	HSL_PIN_GROUP(p2_sync_clko_ptp),

	/*Alt Function M*/
	HSL_PIN_GROUP(p3_tod_out),
	HSL_PIN_GROUP(p3_clk125_tdi),
	HSL_PIN_GROUP(p3_sync_clko_ptp),

	/*Alt Function N*/
	HSL_PIN_GROUP(p0_led_2),
	HSL_PIN_GROUP(p1_led_2),
	HSL_PIN_GROUP(p2_led_2),
	HSL_PIN_GROUP(p3_led_2),
	HSL_PIN_GROUP(dbg_out_clk),	

	/*Alt Function O*/

	
	/*Alt Function Debug Bus Out*/
	HSL_PIN_GROUP(dbg_out_clk),
	HSL_PIN_GROUP(dbg_bus_out0),
	HSL_PIN_GROUP(dbg_bus_out1),
	HSL_PIN_GROUP(dbg_bus_out12),
	HSL_PIN_GROUP(dbg_bus_out13),
	HSL_PIN_GROUP(dbg_bus_out2),
	HSL_PIN_GROUP(dbg_bus_out3),
	HSL_PIN_GROUP(dbg_bus_out4),
	HSL_PIN_GROUP(dbg_bus_out5),
	HSL_PIN_GROUP(dbg_bus_out6),
	HSL_PIN_GROUP(dbg_bus_out7),
	HSL_PIN_GROUP(dbg_bus_out8),
	HSL_PIN_GROUP(dbg_bus_out9),
	HSL_PIN_GROUP(dbg_bus_out10),
	HSL_PIN_GROUP(dbg_bus_out11),
	HSL_PIN_GROUP(dbg_bus_out14),
	HSL_PIN_GROUP(dbg_bus_out15),
};

/****************************************************************************
 *
 * 4) PINs Functions
 *
 ****************************************************************************/
static const char *const gpio_grps[] = { "gpio0_grp", "gpio1_grp",
										 "gpio2_grp", "gpio3_grp", 
										 "gpio4_grp", "gpio5_grp",
										 "gpio6_grp", "gpio7_grp", 
										 "gpio8_grp", "gpio9_grp", 
										 "gpio10_grp", "gpio11_grp",
   										 "gpio12_grp", "gpio13_grp", 
   										 "gpio14_grp", "gpio15_grp", 
   										 "gpio16_grp", "gpio17_grp",
   										 "gpio18_grp", "gpio19_grp", 
   										 "gpio20_grp", "gpio21_grp" };

static const char *const intn_grps[] =  { "intn_wol_grp", "intn_grp" };

static const char *const led_0_grps[] = { "p0_led_0_grp", "p1_led_0_grp", 
										  "p2_led_0_grp", "p3_led_0_grp" };

static const char *const pps_tod_in_grps[] = { "pps_in_grp", "tod_in_grp" };

static const char *const rtc_refclk_in_grps[] = { "rtc_refclk_in_grp" };
static const char *const pps_out_grps[] = { "p0_pps_out_grp", "p1_pps_out_grp",
											"p2_pps_out_grp", "p3_pps_out_grp"};

static const char *const p0_tod_tdi_ptp_grps[] = { "p0_tod_out_grp", "p0_clk125_tdi_grp",
												   "p0_sync_clko_ptp_grp" };

static const char *const led_1_grps[] = { "p0_led_1_grp", "p1_led_1_grp", 
										  "p2_led_1_grp", "p3_led_1_grp" };

static const char *const mdc_mdo_grps[] = { "mdc_m_grp", "mdo_m_grp" };

static const char *const event_trg_grps[] = { "event_trg_i_grp", "p0_event_trg_o_grp", 
											  "p1_event_trg_o_grp", "p2_event_trg_o_grp",
											  "p3_event_trg_o_grp" };

static const char *const p1_tod_tdi_ptp_grps[] = { "p1_tod_out_grp", "p1_clk125_tdi_grp",
												   "p1_sync_clko_ptp_grp" };

static const char *const intn_wol_grps[] = { "p0_intn_wol_grp", "p1_intn_wol_grp", 
										     "p2_intn_wol_grp", "p3_intn_wol_grp" };

static const char *const p2_tod_tdi_ptp_grps[] = { "p2_tod_out_grp", "p2_clk125_tdi_grp",
											       "p2_sync_clko_ptp_grp" };

static const char *const p3_tod_tdi_ptp_grps[] = { "p3_tod_out_grp", "p3_clk125_tdi_grp", 
												   "p3_sync_clko_ptp_grp" };

static const char *const led_2_grps[] = 	  { "p0_led_2_grp","p1_led_2_grp", 
												"p2_led_2_grp", "p3_led_2_grp" };

static const char *const dbg_out_clk_grps[] = { "dbg_out_clk_grp"};
static const char *const dbg_bus_out_grps[] = { "dbg_bus_out0_grp", "dbg_bus_out1_grp", 
												"dbg_bus_out2_grp",	"dbg_bus_out3_grp", 
												"dbg_bus_out4_grp", "dbg_bus_out5_grp"
												"dbg_bus_out6_grp", "dbg_bus_out7_grp",
												"dbg_bus_out8_grp", "dbg_bus_out9_grp", 
												"dbg_bus_out10_grp", "dbg_bus_out11_grp"
												"dbg_bus_out12_grp", "dbg_bus_out13_grp", 
												"dbg_bus_out14_grp", "dbg_bus_out15_grp"};

static const struct hsl_pin_function pin_functions[] = {
	HSL_PIN_FUNCTION(gpio),
	HSL_PIN_FUNCTION(intn),
	HSL_PIN_FUNCTION(led_0),
	HSL_PIN_FUNCTION(pps_tod_in),
	HSL_PIN_FUNCTION(rtc_refclk_in),
	HSL_PIN_FUNCTION(pps_out),
	HSL_PIN_FUNCTION(p0_tod_tdi_ptp),
	HSL_PIN_FUNCTION(led_1),
	HSL_PIN_FUNCTION(mdc_mdo),
	HSL_PIN_FUNCTION(event_trg),
	HSL_PIN_FUNCTION(p1_tod_tdi_ptp),
	HSL_PIN_FUNCTION(intn_wol),
	HSL_PIN_FUNCTION(p2_tod_tdi_ptp),	
	HSL_PIN_FUNCTION(p3_tod_tdi_ptp),		
	HSL_PIN_FUNCTION(led_2),
	HSL_PIN_FUNCTION(dbg_out_clk),
	HSL_PIN_FUNCTION(dbg_bus_out),	
};

/****************************************************************************
 *
 * 5) PINs Description
 *
 ****************************************************************************/
static struct pinctrl_pin_desc mht_pin_desc[] = {
	PINCTRL_PIN(0, "mfio0"),
	PINCTRL_PIN(1, "mfio1"),
	PINCTRL_PIN(2, "mfio2"),
	PINCTRL_PIN(3, "mfio3"),
	PINCTRL_PIN(4, "mfio4"),
	PINCTRL_PIN(5, "mfio5"),
	PINCTRL_PIN(6, "mfio6"),
	PINCTRL_PIN(7, "mfio7"),
	PINCTRL_PIN(8, "mfio8"),
	PINCTRL_PIN(9, "mfio9"),
	PINCTRL_PIN(10, "mfio10"),
	PINCTRL_PIN(11, "mfio11"),
	PINCTRL_PIN(12, "mfio12"),
	PINCTRL_PIN(13, "mfio13"),
	PINCTRL_PIN(14, "mfio14"),
	PINCTRL_PIN(15, "mfio15"),
	PINCTRL_PIN(16, "mfio16"),
	PINCTRL_PIN(17, "mfio17"),
	PINCTRL_PIN(18, "mfio18"),
	PINCTRL_PIN(19, "mfio19"),
	PINCTRL_PIN(20, "mfio20"),
	PINCTRL_PIN(21, "mfio21"),
};

/****************************************************************************
 *
 * 6) PINs Mapping Setting
 *
 ****************************************************************************/
static unsigned long pin_configs_pu[] = {
	//PIN_CONFIG_OUTPUT_ENABLE,
	PIN_CONFIG_BIAS_PULL_UP,
	PIN_CONFIG_OUTPUT_ENABLE,
};

static unsigned long pin_configs_pd[] = {
	PIN_CONFIG_BIAS_PULL_DOWN,
};

static struct pinctrl_map pin_mapping[] = {
	/*PINs default MUX Setting*/
#if 0
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio0_grp", "gpio"),	
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio1_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio2_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio3_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio4_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio5_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio6_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio7_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio8_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio9_grp", "gpio"),	
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio10_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio11_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio12_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio13_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio14_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio15_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio16_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio17_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio18_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio19_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio20_grp", "gpio"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "gpio21_grp", "gpio"),

#else
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "intn_wol_grp", 		"intn"),	
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "intn_grp", 			"intn"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p0_led_0_grp", 		"led_0"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p1_led_0_grp", 		"led_0"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p2_led_0_grp", 		"led_0"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p3_led_0_grp", 		"led_0"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "pps_in_grp", 			"pps_tod_in"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "tod_in_grp", 			"pps_tod_in"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "rtc_refclk_in_grp",	"rtc_refclk_in"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p0_pps_out_grp", 		"pps_out"),	
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p1_pps_out_grp", 		"pps_out"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p2_pps_out_grp",		"pps_out"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p3_pps_out_grp", 		"pps_out"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p0_tod_out_grp", 		"p0_tod_tdi_ptp"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p0_clk125_tdi_grp", 	"p0_tod_tdi_ptp"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p0_sync_clko_ptp_grp", "p0_tod_tdi_ptp"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p0_led_1_grp", 		"led_1"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p1_led_1_grp", 		"led_1"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p2_led_1_grp", 		"led_1"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "p3_led_1_grp", 		"led_1"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mdc_m_grp", 			"mdc_mdo"),
	PIN_MAP_MUX_GROUP_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mdo_m_grp", 			"mdc_mdo"),
#endif
	
	/*PINs default Config Setting*/
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio0", pin_configs_pu),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio1", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio2", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio3", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio4", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio5", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio6", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio7", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio8", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio9", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio10", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio11", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio12", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio13", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio14", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio15", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio16", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio17", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio18", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio19", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio20", pin_configs_pd),
	PIN_MAP_CONFIGS_PIN_DEFAULT(MHT_PDEV_NAME, MHT_PDEV_NAME, "mfio21", pin_configs_pu),
};

/****************************************************************************
 *
 * 7) PINs GPIO Mapping
 *
 ****************************************************************************/
static struct pinctrl_gpio_range mht_gpio_ranges[] = {
	/*name, id, pin_base, npins*/
	HSL_GPIO_RANGE("mht_gpio", 0, 0, HSL_NGPIOS_MAX),
	//HSL_GPIO_RANGE("mht_gpio", 0, 0, 11),
	//HSL_GPIO_RANGE("mht_gpio", 1, 12, 3),	

};

static struct hsl_pinctrl mht_pinctrl = {
	.groups = pin_groups,
	.num_groups = ARRAY_SIZE(pin_groups),
	.functions = pin_functions,
	.num_functions = ARRAY_SIZE(pin_functions),
	.pin_desc = mht_pin_desc,
	.num_pins = ARRAY_SIZE(mht_pin_desc),
	.pin_map = pin_mapping,
	.num_map = ARRAY_SIZE(pin_mapping),
 	.gpioranges = mht_gpio_ranges,
 	.ngpioranges = ARRAY_SIZE(mht_gpio_ranges),	
};

/****************************************************************************
 *
 * 8) PINs Operations
 *
 ****************************************************************************/
static unsigned int DEBUG_PINCTRL_REG[100000] =  {0};
sw_error_t _hsl_reg_field_get(a_uint32_t dev_id, a_uint32_t reg_addr,
						a_uint32_t bit_offset, a_uint32_t field_len,
						a_uint8_t value[], a_uint32_t value_len)
{
	a_uint32_t reg_val = 0;
	
	reg_val = DEBUG_PINCTRL_REG[reg_addr-TLMM_GPIO_CFGN_OFFSET];
	*((a_uint32_t *) value) = SW_REG_2_FIELD(reg_val, bit_offset, field_len);
	//printk("***%s   %x:%x***\n", __func__, reg_addr, reg_val);
	
	return SW_OK;
}

sw_error_t _hsl_reg_field_set(a_uint32_t dev_id, a_uint32_t reg_addr,
						a_uint32_t bit_offset, a_uint32_t field_len,
						const a_uint8_t value[], a_uint32_t value_len)
{
	a_uint32_t reg_val = 0;
	a_uint32_t field_val = *((a_uint32_t *) value);

	SW_REG_SET_BY_FIELD_U32(reg_val, field_val, bit_offset, field_len);
	DEBUG_PINCTRL_REG[reg_addr-TLMM_GPIO_CFGN_OFFSET] = reg_val;
	//printk("***%s   %x:%x***\n", __func__, reg_addr, reg_val);

	return SW_OK;
}

static int mht_gpio_set_bit(unsigned int pin, int value)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;
	
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_IN_OUTN, pin, GPIO_OUT,
					  (unsigned char *) (&value), sizeof (unsigned int));
	printk("[%s] select pin:%d value:%d\n", __func__, pin, value);
	return 0;
}

static int mht_gpio_get_bit(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;
	unsigned int data = 0;
	
	HSL_REG_FIELD_GET(rv, dev_id, TLMM_GPIO_IN_OUTN, pin, GPIO_IN,
					  (unsigned char *) (&data), sizeof (unsigned int));
	printk("[%s] select pin:%d value:%d\n", __func__, pin, data);
	return data;
}

static int mht_gpio_pin_func_sel(unsigned int pin, unsigned int func)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;
	
	printk("[%s] select pin:%d func:%d\n", __func__, pin, func);
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_CFGN, pin, FUNC_SEL,
					  (unsigned char *) (&func), sizeof (unsigned int));

	return 0;
}

int mht_gpio_pin_cfg_set_bias(unsigned int pin, int bias)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	int data = 0;

	switch (bias) 
	{
		case PIN_CONFIG_BIAS_DISABLE:
			data = MHT_PIN_CONFIG_BIAS_DISABLE;
			break;
		case PIN_CONFIG_BIAS_PULL_DOWN:
			data = MHT_PIN_CONFIG_BIAS_PULL_DOWN;
			break;			
		case PIN_CONFIG_BIAS_BUS_HOLD:
			data = MHT_PIN_CONFIG_BIAS_BUS_HOLD;
			break;			
		case PIN_CONFIG_BIAS_PULL_UP:
			data = MHT_PIN_CONFIG_BIAS_PULL_UP;
			break;
		default:
			printk("[%s] doesn't support bias:%d\n", __func__, bias);			
			return -1;
	}

	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_CFGN, pin, GPIO_PULL,
					  (unsigned char *) (&data), sizeof (unsigned int));
	printk("[%s]pin:%d bias:%d", __func__, pin, bias);
	
	return 0;
}

int mht_gpio_pin_cfg_get_bias(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	int data = 0, bias = 0;

	HSL_REG_FIELD_GET(rv, dev_id, TLMM_GPIO_CFGN, pin, GPIO_PULL,
					  (unsigned char *) (&data), sizeof (unsigned int));	
	switch (data) 
	{
		case MHT_PIN_CONFIG_BIAS_DISABLE:	//Disables all pull
			bias = PIN_CONFIG_BIAS_DISABLE;
			break;
		case MHT_PIN_CONFIG_BIAS_PULL_DOWN:
			bias = PIN_CONFIG_BIAS_PULL_DOWN;
			break;			
		case MHT_PIN_CONFIG_BIAS_BUS_HOLD:	//Weak Keepers
			bias = PIN_CONFIG_BIAS_BUS_HOLD;
			break;			
		case MHT_PIN_CONFIG_BIAS_PULL_UP:
			bias = PIN_CONFIG_BIAS_PULL_UP;
			break;
		default:
			printk("[%s] doesn't support bias:%d\n", __func__, bias);				
			return -1;		
	}
	printk("[%s]pin:%d bias:%d", __func__, pin, bias);

	return bias;
}

int mht_gpio_pin_cfg_set_drvs(unsigned int pin, int drvs)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;

	if((drvs < MHT_PIN_DRV_2_MA) || (drvs > MHT_PIN_DRV_16_MA)) {
		printk("[%s] doesn't support drvs:%d\n", __func__, drvs);
		return -1;
	}

	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_CFGN, pin, DRV_STRENGTH,
					  (unsigned char *) (&drvs), sizeof (unsigned int));
	printk("[%s]%d", __func__, pin);
	
	return 0;
}

int mht_gpio_pin_cfg_get_drvs(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	int drvs = 0;

	HSL_REG_FIELD_GET(rv, dev_id, TLMM_GPIO_CFGN, pin, DRV_STRENGTH,
					  (unsigned char *) (&drvs), sizeof (unsigned int));
	printk("[%s]%d", __func__, pin);
	
	return drvs;
}

int mht_gpio_pin_cfg_set_oe(unsigned int pin, bool oe)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;

	printk("[%s]%d oe:%d", __func__, pin, oe);

	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_CFGN, pin, GPIO_OE,
					  (unsigned char *) (&oe), sizeof (unsigned int));
	
	return 0;
}

bool mht_gpio_pin_cfg_get_oe(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	int oe = false;

	HSL_REG_FIELD_GET(rv, dev_id, TLMM_GPIO_CFGN, pin, GPIO_OE,
					  (unsigned char *) (&oe), sizeof (unsigned int));
	
	printk("[%s]%d oe:%d", __func__, pin, oe);

	return oe;
}

#ifdef MHT_GPIO_IRQ
static void mht_gpio_irq_enable(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	unsigned int data = 1;

	printk("[%s]%d:%d", __func__, pin, data);
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_INTR_CFGN, pin, INTR_ENABLE,
					  (unsigned char *) (&data), sizeof (unsigned int));
}

static void mht_gpio_irq_disable(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	unsigned int data = 0;

	printk("[%s]%d:%d", __func__, pin, data);
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_INTR_CFGN, pin, INTR_ENABLE,
					  (unsigned char *) (&data), sizeof (unsigned int));
}

static int mht_gpio_irq_set_type(unsigned int pin, unsigned int type)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	unsigned int edge  = 0;
	unsigned int high = 0;

	switch (type) 
	{
		case IRQ_TYPE_EDGE_RISING:
			edge  = 3;
			high = 1;
			break;
		case IRQ_TYPE_EDGE_FALLING:
			edge  = 3;
			high = 0;
			break;			
		case IRQ_TYPE_LEVEL_HIGH:
			edge  = 0;
			high = 1;
			break;			
		case IRQ_TYPE_LEVEL_LOW:
			edge  = 0;
			high = 0;
			break;
		default:
			printk("[%s] doesn't support type:%d\n", __func__, type);			
			return -1;
	}
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_INTR_CFGN, pin, INTR_DECT_CTL,
					  (unsigned char *) (&edge), sizeof (unsigned int));
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_INTR_CFGN, pin, INTR_POL_CTL,
					  (unsigned char *) (&high), sizeof (unsigned int));	


	printk("[%s]:%d", __func__, type);
	
	return 0;
}

static void mht_gpio_irq_ack(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	unsigned int data = 1;
	
	printk("[%s]:%d", __func__, pin);
	HSL_REG_FIELD_SET(rv, dev_id, TLMM_GPIO_INTR_STATUSN, pin, INTR_STATUS,
					  (unsigned char *) (&data), sizeof (unsigned int));	
}

static int mht_gpio_irq_status(unsigned int pin)
{
	sw_error_t rv;
	a_uint32_t dev_id = 0;	
	unsigned int data = 0;

	printk("[%s]:%d", __func__, pin);	
	HSL_REG_FIELD_GET(rv, dev_id, TLMM_GPIO_INTR_STATUSN, pin, INTR_STATUS,
					  (unsigned char *) (&data), sizeof (unsigned int));

	return data;
}
#endif

/****************************************************************************
 *
 * 9) PINs Init
 *
 ****************************************************************************/
struct hsl_pinctrl * mht_pinctrl_init(struct platform_device *pdev)
{
	struct hsl_pinctrl *pinctrl = &mht_pinctrl;
	struct hsl_pinctrl_ops_t *ops = &pinctrl->ops;

	pinctrl->dev = &pdev->dev;
	pdev->name = MHT_PDEV_NAME;

	ops->gpio_set_bit = mht_gpio_set_bit;
	ops->gpio_get_bit = mht_gpio_get_bit;
	ops->gpio_pin_func_sel = mht_gpio_pin_func_sel;	
	ops->gpio_pin_cfg_set_bias = mht_gpio_pin_cfg_set_bias;
	ops->gpio_pin_cfg_get_bias = mht_gpio_pin_cfg_get_bias;
	ops->gpio_pin_cfg_set_drvs = mht_gpio_pin_cfg_set_drvs;
	ops->gpio_pin_cfg_get_drvs = mht_gpio_pin_cfg_get_drvs;
	ops->gpio_pin_cfg_set_oe = mht_gpio_pin_cfg_set_oe;
	ops->gpio_pin_cfg_get_oe = mht_gpio_pin_cfg_get_oe;	

#ifdef MHT_GPIO_IRQ
	ops->gpio_irq_enable = mht_gpio_irq_enable;
	ops->gpio_irq_disable = mht_gpio_irq_disable;
	ops->gpio_irq_set_type = mht_gpio_irq_set_type;
	ops->gpio_irq_ack = mht_gpio_irq_ack;
	ops->gpio_irq_status = mht_gpio_irq_status;
#endif	

	return pinctrl;
}

