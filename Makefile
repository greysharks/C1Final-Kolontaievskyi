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

GENERAL = -Wall -Werror -g -O0
CPPFLAGS = $(GENERAL) -D$(PLATFORM) $(INCLUDES)
CFLAGS = $(CPPFLAGS) -std=c99
LDFLAGS = -Wl,-Map=$(TARGET).map

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld

	SIZE = size
	OBJDUMP = objdump
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	ARMFLAGS = -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16

	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS += -T $(LINKER_FILE)
	CFLAGS += -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) $(ARMFLAGS)
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
endif

TARGET = c1m2

OBJS := $(SOURCES:.c=.o)
DEPS := $(SOURCES:.c=.d)

%.i : %.c
	$(CC) -E $^ $(CPPFLAGS) -o $@

%.o : %.c
	$(CC) -c $^ $(CFLAGS) -MD -o $@

%.asm : %.c
	$(CC) -S $^ $(CFLAGS) -o $@

$(TARGET).asm: build
	$(OBJDUMP) -d $(TARGET).out > $(TARGET).asm

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f *o *d *out *map *i *asm
