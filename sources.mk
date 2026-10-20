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

SRC_PATH = ./src
INCLUDE_PATH = ./include

SOURCES = $(SRC_PATH)/memory.c \
  $(SRC_PATH)/main.c \
  $(SRC_PATH)/stats.c \
  $(SRC_PATH)/data.c \
  $(SRC_PATH)/course1.c

INCLUDES = -I $(INCLUDE_PATH)/common

# Add your Source files to this variable
ifeq ($(PLATFORM),MSP432)
	SOURCES += $(SRC_PATH)/system_msp432p401r.c  \
	  $(SRC_PATH)/interrupts_msp432p401r_gcc.c  \
          $(SRC_PATH)/startup_msp432p401r_gcc.c \

	INCLUDES += -I $(INCLUDE_PATH)/msp432 \
	  -I $(INCLUDE_PATH)/CMSIS
endif
