LOC_DIR=src/hsl/mrppe
LIB=HSL

include $(PRJ_PATH)/make/config.mk

ifeq (TRUE, $(IN_PKTEDIT))
  SRC_LIST+=mrppe_pktedit.c
endif

ifeq (, $(filter MRPPE, $(SUPPORT_CHIP)))
  SRC_LIST=
endif

include $(PRJ_PATH)/make/components.mk
include $(PRJ_PATH)/make/defs.mk
include $(PRJ_PATH)/make/target.mk

all: dep obj
