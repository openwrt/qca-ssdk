LOC_DIR=src/hsl/mht
LIB=HSL

include $(PRJ_PATH)/make/config.mk

SRC_LIST= mht_init.c mht_sec_ctrl.c

ifeq (TRUE, $(IN_IP))
	SRC_LIST += mht_ip.c
endif

ifeq (, $(findstring MHT, $(SUPPORT_CHIP)))
	SRC_LIST=
endif

include $(PRJ_PATH)/make/components.mk
include $(PRJ_PATH)/make/defs.mk
include $(PRJ_PATH)/make/target.mk

all: dep obj
