# Remove the common OLED display code - we're implementing our own
SRC := $(filter-out keyboards/mechboards/common/display_oled.c, $(SRC))
