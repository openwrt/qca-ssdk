LOC_DIR=src/hsl/appe
LIB=HSL

include $(PRJ_PATH)/make/config.mk

SRC_LIST=appe_global.c

ifeq (, $(filter APPE, $(SUPPORT_CHIP)))
  SRC_LIST=
endif
include $(PRJ_PATH)/make/components.mk
include $(PRJ_PATH)/make/defs.mk
include $(PRJ_PATH)/make/target.mk

all: dep obj

