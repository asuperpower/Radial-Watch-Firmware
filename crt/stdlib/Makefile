# Makefile for Radial Technologies C-Runtime Library
#
# Quaker762
#
# Purpose:
#

PROJECT = crt

# Project Structure
OBJDIR = ../obj
SRC := $(wildcard *.c)
OBJS := $(patsubst %.c,../obj/%.o, $(wildcard *.c))
INCDIR = ../h
CPU = cortex-m4

INCLUDE = -I $(INCDIR)

# C Flags
GCFLAGS  = -Wall -fno-common -mthumb -mcpu=$(CPU)
GCFLAGS += $(INCLUDE)
LDFLAGS += -nostartfiles -T$(LSCRIPT) -mthumb -mcpu=$(CPU) 
ASFLAGS += -mcpu=$(CPU)

# Tools
CC = 		arm-none-eabi-gcc
AS = 		arm-none-eabi-as
AR = 		arm-none-eabi-ar
LD = 		arm-none-eabi-ld
MAKE = 		mingw32-make.exe
OBJCOPY = 	arm-none-eabi-objcopy
SIZE = 		arm-none-eabi-size
OBJDUMP = 	arm-none-eabi-objdump

RM = rm -rf

lib: $(OBJS)
	
../obj/%.o: %.c
	$(CC) $(GCFLAGS) -c $< -o $@
	

	
	

	