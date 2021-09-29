
/* TLMM_GPIO_CFGn */
#define TLMM_GPIO_CFGN
#define TLMM_GPIO_CFGN_OFFSET 	   0xC400000
#define TLMM_GPIO_CFGN_E_LENGTH	   4
#define TLMM_GPIO_CFGN_E_OFFSET    0x1000
#define TLMM_GPIO_CFGN_NR_E		   80


#define GPIO_HIHYS_EN
#define TLMM_GPIO_CFGN_GPIO_HIHYS_EN_BOFFSET	10
#define TLMM_GPIO_CFGN_GPIO_HIHYS_EN_BLEN		1
#define TLMM_GPIO_CFGN_GPIO_HIHYS_EN_FLAG		HSL_RW

#define GPIO_OE
#define TLMM_GPIO_CFGN_GPIO_OE_BOFFSET		 	9
#define TLMM_GPIO_CFGN_GPIO_OE_BLEN			 	1
#define TLMM_GPIO_CFGN_GPIO_OE_FLAG			 	HSL_RW

#define DRV_STRENGTH
#define TLMM_GPIO_CFGN_DRV_STRENGTH_BOFFSET		6
#define TLMM_GPIO_CFGN_DRV_STRENGTH_BLEN		3
#define TLMM_GPIO_CFGN_DRV_STRENGTH_FLAG		HSL_RW

#define FUNC_SEL
#define TLMM_GPIO_CFGN_FUNC_SEL_BOFFSET			2
#define TLMM_GPIO_CFGN_FUNC_SEL_BLEN			4
#define TLMM_GPIO_CFGN_FUNC_SEL_FLAG			HSL_RW

#define GPIO_PULL
#define TLMM_GPIO_CFGN_GPIO_PULL_BOFFSET		0
#define TLMM_GPIO_CFGN_GPIO_PULL_BLEN			2
#define TLMM_GPIO_CFGN_GPIO_PULL_FLAG			HSL_RW


/* TLMM_GPIO_IN_OUTn */
#define TLMM_GPIO_IN_OUTN
#define TLMM_GPIO_IN_OUTN_OFFSET 	   0xC400004
#define TLMM_GPIO_IN_OUTN_E_LENGTH	   4
#define TLMM_GPIO_IN_OUTN_E_OFFSET     0x1000
#define TLMM_GPIO_IN_OUTN_NR_E		   80

#define GPIO_OUT
#define TLMM_GPIO_IN_OUTN_GPIO_OUT_BOFFSET	1
#define TLMM_GPIO_IN_OUTN_GPIO_OUT_BLEN		1
#define TLMM_GPIO_IN_OUTN_GPIO_OUT_FLAG		HSL_RW

#define GPIO_IN
#define TLMM_GPIO_IN_OUTN_GPIO_IN_BOFFSET		0
#define TLMM_GPIO_IN_OUTN_GPIO_IN_BLEN			1
#define TLMM_GPIO_IN_OUTN_GPIO_IN_FLAG			HSL_R


/* TLMM_CLK_GATE_EN */
#define TLMM_CLK_GATE_EN
#define TLMM_CLK_GATE_EN_OFFSET 	   	0xC500000
#define TLMM_CLK_GATE_EN_E_LENGTH		4
#define TLMM_CLK_GATE_EN_E_OFFSET   	0
#define TLMM_CLK_GATE_EN_NR_E			1

#define AHB_HCLK_EN
#define TLMM_CLK_GATE_EN_AHB_HCLK_EN_BOFFSET		2
#define TLMM_CLK_GATE_EN_AHB_HCLK_EN_BLEN			1
#define TLMM_CLK_GATE_EN_AHB_HCLK_EN_FLAG			HSL_RW

#define SUMMARY_INTR_EN
#define TLMM_CLK_GATE_EN_SUMMARY_INTR_EN_BOFFSET	1
#define TLMM_CLK_GATE_EN_SUMMARY_INTR_EN_BLEN		1
#define TLMM_CLK_GATE_EN_SUMMARY_INTR_EN_FLAG		HSL_RW

#define CRIF_READ_EN
#define TLMM_CLK_GATE_EN_CRIF_READ_EN_BOFFSET		0
#define TLMM_CLK_GATE_EN_CRIF_READ_EN_BLEN			1
#define TLMM_CLK_GATE_EN_CRIF_READ_EN_FLAG			HSL_RW


/* TLMM_HW_REVISION_NUMBER */
#define TLMM_HW_REVISION_NUMBER
#define TLMM_HW_REVISION_NUMBER_OFFSET 	   	0xC510010
#define TLMM_HW_REVISION_NUMBER_E_LENGTH	4
#define TLMM_HW_REVISION_NUMBER_E_OFFSET   	0
#define TLMM_HW_REVISION_NUMBER_NR_E		1

#define VERSION_ID
#define TLMM_HW_REVISION_NUMBER_VERSION_ID_BOFFSET	28
#define TLMM_HW_REVISION_NUMBER_VERSION_ID_BLEN		4
#define TLMM_HW_REVISION_NUMBER_VERSION_ID_FLAG		HSL_R

#define PARTNUM
#define TLMM_HW_REVISION_NUMBER_PARTNUM_BOFFSET		12
#define TLMM_HW_REVISION_NUMBER_PARTNUM_BLEN		16
#define TLMM_HW_REVISION_NUMBER_PARTNUM_FLAG		HSL_R

#define QCOM_MFG_ID
#define TLMM_HW_REVISION_NUMBER_QCOM_MFG_ID_BOFFSET	1
#define TLMM_HW_REVISION_NUMBER_QCOM_MFG_ID_BLEN	11
#define TLMM_HW_REVISION_NUMBER_QCOM_MFG_ID_FLAG	HSL_R

#define START_BIT
#define TLMM_HW_REVISION_NUMBER_START_BIT_BOFFSET	0
#define TLMM_HW_REVISION_NUMBER_START_BIT_BLEN		1
#define TLMM_HW_REVISION_NUMBER_START_BIT_FLAG		HSL_R

#ifdef MHT_GPIO_IRQ
/* TLMM_GPIO_INTR_CFGn */
#define TLMM_GPIO_INTR_CFGN
#define TLMM_GPIO_INTR_CFGN_OFFSET 	   	0XC400008
#define TLMM_GPIO_INTR_CFGN_E_LENGTH	4
#define TLMM_GPIO_INTR_CFGN_E_OFFSET    0X1000
#define TLMM_GPIO_INTR_CFGN_NR_E		80

#define DIR_CONN_EN
#define TLMM_GPIO_INTR_CFGN_DIR_CONN_EN_BOFFSET			8
#define TLMM_GPIO_INTR_CFGN_DIR_CONN_EN_BLEN			1
#define TLMM_GPIO_INTR_CFGN_DIR_CONN_EN_FLAG			HSL_RW

#define TARGET_PROC
#define TLMM_GPIO_INTR_CFGN_TARGET_PROC_BOFFSET			5
#define TLMM_GPIO_INTR_CFGN_TARGET_PROC_BLEN			3
#define TLMM_GPIO_INTR_CFGN_TARGET_PROC_FLAG			HSL_RW

#define INTR_RAW_STATUS_EN
#define TLMM_GPIO_INTR_CFGN_INTR_RAW_STATUS_EN_BOFFSET	4
#define TLMM_GPIO_INTR_CFGN_INTR_RAW_STATUS_EN_BLEN		1
#define TLMM_GPIO_INTR_CFGN_INTR_RAW_STATUS_EN_FLAG		HSL_RW

#define INTR_DECT_CTL
#define TLMM_GPIO_INTR_CFGN_INTR_DECT_CTL_BOFFSET		2
#define TLMM_GPIO_INTR_CFGN_INTR_DECT_CTL_BLEN			2
#define TLMM_GPIO_INTR_CFGN_INTR_DECT_CTL_FLAG			HSL_RW

#define INTR_POL_CTL
#define TLMM_GPIO_INTR_CFGN_INTR_POL_CTL_BOFFSET		1
#define TLMM_GPIO_INTR_CFGN_INTR_POL_CTL_BLEN			1
#define TLMM_GPIO_INTR_CFGN_INTR_POL_CTL_FLAG			HSL_RW

#define INTR_ENABLE
#define TLMM_GPIO_INTR_CFGN_INTR_ENABLE_BOFFSET			0
#define TLMM_GPIO_INTR_CFGN_INTR_ENABLE_BLEN			1
#define TLMM_GPIO_INTR_CFGN_INTR_ENABLE_FLAG			HSL_RW


/* TLMM_GPIO_INTR_STATUSn */
#define TLMM_GPIO_INTR_STATUSN
#define TLMM_GPIO_INTR_STATUSN_OFFSET 	   	0xC40000C
#define TLMM_GPIO_INTR_STATUSN_E_LENGTH		4
#define TLMM_GPIO_INTR_STATUSN_E_OFFSET    	0X1000
#define TLMM_GPIO_INTR_STATUSN_NR_E			80

#define INTR_STATUS
#define TLMM_GPIO_INTR_STATUSN_INTR_STATUS_BOFFSET		0
#define TLMM_GPIO_INTR_STATUSN_INTR_STATUS_BLEN			1
#define TLMM_GPIO_INTR_STATUSN_INTR_STATUS_FLAG			HSL_RW
#endif

enum mht_pin_config_param {
	MHT_PIN_CONFIG_BIAS_DISABLE,
	MHT_PIN_CONFIG_BIAS_PULL_DOWN,
	MHT_PIN_CONFIG_BIAS_BUS_HOLD,
	MHT_PIN_CONFIG_BIAS_PULL_UP,
};

enum mht_pin_drv_strength {
	MHT_PIN_DRV_2_MA,
	MHT_PIN_DRV_4_MA,
	MHT_PIN_DRV_6_MA,
	MHT_PIN_DRV_8_MA,
	MHT_PIN_DRV_10_MA, 
	MHT_PIN_DRV_12_MA, 
	MHT_PIN_DRV_14_MA, 
	MHT_PIN_DRV_16_MA,
};


#define HSL_NGPIOS_MAX 22
#define MHT_PDEV_NAME "pinctrl-mht"

struct hsl_pinctrl * mht_pinctrl_init(struct platform_device *pdev);



#if 1

typedef   __u8              __a_uint8_t;
typedef   __s8              __a_int8_t;
typedef   __u16             __a_uint16_t;
typedef   __s16             __a_int16_t;
typedef   __u32             __a_uint32_t;
typedef   __s32             __a_int32_t;
typedef   __u64             __a_uint64_t;
typedef   __s64             __a_int64_t;

typedef __a_uint8_t	  a_uint8_t;
typedef __a_int8_t	  a_int8_t;
typedef __a_uint16_t   a_uint16_t;
typedef __a_int16_t	  a_int16_t;
typedef __a_uint32_t   a_uint32_t;
typedef __a_int32_t	  a_int32_t;
typedef __a_uint64_t   a_uint64_t;
typedef __a_int64_t	  a_int64_t;
typedef unsigned long  a_ulong_t;

typedef enum {
   SW_OK			  = 0,		 /* Operation succeeded 				*/
   SW_FAIL			  = -1, 	 /* Operation failed					*/
   SW_BAD_VALUE 	  = -2, 	 /* Illegal value						*/
   SW_OUT_OF_RANGE	  = -3, 	 /* Value is out of range				*/
   SW_BAD_PARAM 	  = -4, 	 /* Illegal parameter(s)				*/
   SW_BAD_PTR		  = -5, 	 /* Illegal pointer value				*/
   SW_BAD_LEN		  = -6, 	 /* Wrong length						*/
   SW_BAD_STATE 	  = -7, 	 /* Wrong state of state machine		*/
   SW_READ_ERROR	  = -8, 	 /* Read operation failed				*/
   SW_WRITE_ERROR	  = -9, 	 /* Write operation failed				*/
   SW_CREATE_ERROR	  = -10,	 /* Fail in creating an entry			*/
   SW_DELETE_ERROR	  = -11,	 /* Fail in deleteing an entry			*/
   SW_NOT_FOUND 	  = -12,	 /* Entry not found 					*/
   SW_NO_CHANGE 	  = -13,	 /* The parameter(s) is the same		*/
   SW_NO_MORE		  = -14,	 /* No more entry found 				*/
   SW_NO_SUCH		  = -15,	 /* No such entry						*/
   SW_ALREADY_EXIST   = -16,	 /* Tried to create existing entry		*/
   SW_FULL			  = -17,	 /* Table is full						*/
   SW_EMPTY 		  = -18,	 /* Table is empty						*/
   SW_NOT_SUPPORTED   = -19,	 /* This request is not support 		*/
   SW_NOT_IMPLEMENTED = -20,	 /* This request is not implemented 	*/
   SW_NOT_INITIALIZED = -21,	 /* The item is not initialized 		*/
   SW_BUSY			  = -22,	 /* Operation is still running			*/
   SW_TIMEOUT		  = -23,	 /* Operation Time Out					*/
   SW_DISABLE		  = -24,	 /* Operation is disabled				*/
   SW_NO_RESOURCE	  = -25,	 /* Resource not available (memory ...) */
   SW_INIT_ERROR	  = -26,	 /* Error occured while INIT process	*/
   SW_NOT_READY 	  = -27,	 /* The other side is not ready yet 	*/
   SW_OUT_OF_MEM	  = -28,	 /* Cpu memory allocation failed.		*/
   SW_ABORTED		  = -29 	 /* Operation has been aborted. 		*/
} sw_error_t;

 /* register functions */
#define SW_BIT_MASK_U32(nr) (~(0xFFFFFFFF << (nr)))

#define SW_FIELD_MASK_U32(offset, len) \
   ((SW_BIT_MASK_U32(len) << (offset)))

#define SW_FIELD_MASK_NOT_U32(offset,len) \
   (~(SW_BIT_MASK_U32(len) << (offset)))

#define SW_FIELD_2_REG(field_val, bit_offset) \
   (field_val << (bit_offset) )

#define SW_REG_2_FIELD(reg_val, bit_offset, field_len) \
   (((reg_val) >> (bit_offset)) & ((1 << (field_len)) - 1))

#define SW_REG_SET_BY_FIELD_U32(reg_value, field_value, bit_offset, field_len)\
   do { \
	   (reg_value) = \
		   (((reg_value) & SW_FIELD_MASK_NOT_U32((bit_offset),(field_len))) \
			 | (((field_value) & SW_BIT_MASK_U32(field_len)) << (bit_offset)));\
   } while (0)



#define HSL_REG_FIELD_SET(rv, dev, reg, index, field, value, val_len) \
									rv = _hsl_reg_field_set(dev, reg##_OFFSET + ((a_uint32_t)index) * reg##_E_OFFSET,\
                                   reg##_##field##_BOFFSET, \
                                   reg##_##field##_BLEN, (a_uint8_t*)value, val_len);


#define HSL_REG_FIELD_GET(rv, dev, reg, index, field, value, val_len) \
									rv = _hsl_reg_field_get(dev,reg##_OFFSET + ((a_uint32_t)index) * reg##_E_OFFSET,\
								   reg##_##field##_BOFFSET, \
								   reg##_##field##_BLEN,value,val_len);

#endif

