#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
# Platform Overrides
PLATFORM ?= HOST

include sources.mk

# Default variables for both platforms
GENERAL = -Wall -Werror -g -O0
CPPFLAGS = $(GENERAL) -D$(PLATFORM) $(INCLUDES)
CFLAGS = $(CPPFLAGS) -std=c99 -DCOURSE1 -DVERBOSE
LDFLAGS = -Wl,-Map=$(TARGET).map

# Default variables for HOST platform
CC = gcc
LD = ld
SIZE = size
OBJDUMP = objdump

# Default variables for TARGET platfrom (MSP4)
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	ARMFLAGS = -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16

	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	LINKER_FILE = msp432p401r.lds
	LDFLAGS += -T $(LINKER_FILE)
	CFLAGS += -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) $(ARMFLAGS)
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
endif

TARGET = course1

OBJS := $(SOURCES:.c=.o)
DEPS := $(SOURCES:.c=.d)

%.i : %.c
	$(CC) -E $^ $(CPPFLAGS) -o $@

%.o : %.c
	$(CC) -c $^ $(CFLAGS) -MD -o $@

%.asm : %.c
	$(CC) -S $^ $(CFLAGS) -o $@

$(TARGET).asm: build
	$(OBJDUMP) -d $(SRC_PATH)/$(TARGET).out > $(SRC_PATH)/$(TARGET).asm

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f $(SRC_PATH)/*.o $(SRC_PATH)/*.d *.out *.map $(SRC_PATH)/*.i $(SRC_PATH)/*.asm
