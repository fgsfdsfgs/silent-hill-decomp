# Names and Paths

GAME_NAME		:= SLUS-00707
MAIN_NAME   	:= SLUS_007.07
SEG_1_NAME		:= SILENT
SEG_2_NAME		:= HILL

ROM_DIR			:= rom
IMAGE_DIR		:= $(ROM_DIR)/image
BUILD_DIR       := build
TOOLS_DIR       := tools

TARGET_BOOT		:= $(BUILD_DIR)/$(MAIN_NAME)

# Source Definitions

ASM_DIR_BOOT	:= asm/main asm/main/data
C_DIR_BOOT		:= src/main
BIN_DIR_BOOT	:= assets/main

S_FILES_BOOT	:= $(foreach dir,$(ASM_DIR_BOOT),$(wildcard $(dir)/*.s))
C_FILES_BOOT	:= $(foreach dir,$(C_DIR_BOOT),$(wildcard $(dir)/*.c))
BIN_FILES_BOOT	:= $(foreach dir,$(BIN_DIR_BOOT),$(wildcard $(dir)/*.bin))

O_FILES_BOOT	:= $(foreach file,$(S_FILES_BOOT),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(C_FILES_BOOT),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(BIN_FILES_BOOT),$(BUILD_DIR)/$(file).o)

ASM_DIRS_ALL	:= $(ASM_DIR_BOOT)
C_DIRS_ALL		:= $(C_DIR_BOOT)
BIN_DIRS_ALL	:= $(BIN_DIR_BOOT)

# Tools
PYTHON          := python3
WINE            := wine
CPP             := cpp
CROSS			:= mips-linux-gnu-
AS              := $(CROSS)as -EL
LD              := $(CROSS)ld -EL
OBJCOPY         := $(CROSS)objcopy
CC_272			:= $(TOOLS_DIR)/psyq/272/cc1 # Native 2.7.2
CC_PSYQ_36     	:= $(WINE) $(TOOLS_DIR)/psyq/3.6/CC1PSX.EXE # 2.7.2.SN.1
CC_PSYQ_41      := $(WINE) $(TOOLS_DIR)/psyq/4.1/CC1PSX.EXE	# cygnus-2.7.2-970404
CC_PSYQ_43      := $(WINE) $(TOOLS_DIR)/psyq/4.3/CC1PSX.EXE # 2.8.1 SN32
CC_PSYQ_46      := $(WINE) $(TOOLS_DIR)/psyq/4.6/CC1PSX.EXE # 2.95
CC              := $(CC_272)
SPLAT           := $(PYTHON) $(TOOLS_DIR)/splat/split.py
EXTRACT			:= $(TOOLS_DIR)/extractDisk.sh

# Flags
OPT_FLAGS       := -O2
INCLUDE_CFLAGS	:= -Iinclude
AS_FLAGS        := -march=r3000 -mtune=r3000 -Iinclude
D_FLAGS       	:= -D_LANGUAGE_C
CC_FLAGS        := -G 0 -mips1 -mcpu=3000 -mgas -msoft-float $(OPT_FLAGS) -fgnu-linker
CPP_FLAGS       := -undef -Wall -lang-c $(DFLAGS) $(INCLUDE_CFLAGS) -nostdinc
OBJCOPY_FLAGS   := -O binary

# Rules
default: all

all: dirs $(TARGET_BOOT) check

check: $(TARGET_BOOT)
	cat $(ROM_DIR)/sha1/$(MAIN_NAME).sha1
	sha1sum $<
	@touch $@

extract:
	$(EXTRACT) $(GAME_NAME) $(IMAGE_DIR) $(ROM_DIR) 

generate:
	$(SPLAT) $(MAIN_NAME).yaml

dirs:
	$(foreach dir,$(ASM_DIRS_ALL) $(C_DIRS_ALL) $(BIN_DIRS_ALL),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

clean:
	rm -rf $(BUILD_DIR)

clean-rom:
	find rom -maxdepth 1 -type f -delete

reset:
	rm -rf asm
	rm -rf assets
	rm -rf linker
	rm -rf meta/*auto*.txt 

setup: | clean reset clean-rom extract generate

regenerate: | clean reset generate

# bootloader
$(TARGET_BOOT): $(TARGET_BOOT).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(TARGET_BOOT).elf: $(O_FILES_BOOT)
	$(LD) -Map $(TARGET_BOOT).map -T linker/$(MAIN_NAME).ld -T meta/undefined_symbols_auto.main.txt -T meta/undefined_functions_auto.main.txt -T meta/undefined_symbols.main.txt --no-check-sections -o $@

# generate objects
$(BUILD_DIR)/%.i: %.c
	$(CPP) -P -MMD -MP -MT $@ -MF $@.d $(CPP_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.s: $(BUILD_DIR)/%.i
	$(CC) $(CC_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.s
	$(AS) $(AS_FLAGS) -o $@ $<

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
