OPT_DEFS += -DFACTORY_TEST_ENABLE -DAPDAPTIVE_NKRO_ENABLE -DVIA_INSECURE

KEYCHRON_COMMON_DIR = $(TOP_DIR)/keyboards/keychron/common
SRC += \
    $(KEYCHRON_COMMON_DIR)/keychron_task.c \
    $(KEYCHRON_COMMON_DIR)/keychron_common.c \
    $(KEYCHRON_COMMON_DIR)/keychron_raw_hid.c \
    $(KEYCHRON_COMMON_DIR)/factory_test.c \
    $(KEYCHRON_COMMON_DIR)/backlit_indicator.c \
    $(KEYCHRON_COMMON_DIR)/eeconfig_kb.c \
    $(KEYCHRON_COMMON_DIR)/dfu_info.c

VPATH += $(KEYCHRON_COMMON_DIR)

INFO_RULES_MK = $(shell $(QMK_BIN) generate-rules-mk --quiet --escape --keyboard $(KEYBOARD) --output $(INTERMEDIATE_OUTPUT)/src/info_rules.mk)
include $(INFO_RULES_MK)

ifeq ($(strip $(DEBOUNCE_TYPE)), custom)
include $(KEYCHRON_COMMON_DIR)/debounce/debounce.mk
endif

include $(KEYCHRON_COMMON_DIR)/language/language.mk
include $(KEYCHRON_COMMON_DIR)/snap_click/snap_click.mk

ifeq ($(strip $(KEYCHRON_RGB_ENABLE)), yes)
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
include $(KEYCHRON_COMMON_DIR)/rgb/rgb.mk
endif
endif

ifeq ($(strip $(USB_REPORT_INTERVAL_ENABLE)), yes)
OPT_DEFS += -DUSB_REPORT_INTERVAL_ENABLE
SRC += $(KEYCHRON_COMMON_DIR)/usb_report_rate.c
endif
