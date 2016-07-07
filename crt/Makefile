# Makefile for Radial Technologies C-Runtime Library
#
# Quaker762
#
# Purpose:
#

PROJECT = libc

# Project Structure
BINDIR = bin
OBJDIR = obj
INCDIR = h
SRCDIRS = stdlib
ECHO = @echo

OBJ := $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

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

# http://crasseux.com/books/ctutorial/Building-a-library.html
# http://www.cs.dartmouth.edu/~campbell/cs50/buildlib.html
# Infomation on generating the C library
all:
	$(ECHO) Compiling C Runtime Library...
	if not exist "bin" mkdir "bin"
	if not exist "obj" mkdir "obj"
	$(ECHO) Compiling stdlib...
	cd stdlib && $(MAKE) lib
	$(ECHO) Compiling string...
	cd string && $(MAKE) lib
	$(ECHO) Building Static Library...
	$(AR) -cvr $(BINDIR)\$(PROJECT).a $(OBJDIR)/*.o
	$(ECHO) Checking archived files...
	$(AR) -t $(BINDIR)\$(PROJECT).a
	$(ECHO) Done!
	

	