################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
sinDecFreqButtonControl.lss \

FLASH_IMAGE += \
sinDecFreqButtonControl.hex \

EEPROM_IMAGE += \
sinDecFreqButtonControl.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: sinDecFreqButtonControl.elf secondary-outputs

# Tool invocations
sinDecFreqButtonControl.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sinDecFreqButtonControl.map -mmcu=atmega328p -o "sinDecFreqButtonControl.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sinDecFreqButtonControl.lss: sinDecFreqButtonControl.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sinDecFreqButtonControl.elf  >"sinDecFreqButtonControl.lss"
	@echo 'Finished building: $@'
	@echo ' '

sinDecFreqButtonControl.hex: sinDecFreqButtonControl.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex sinDecFreqButtonControl.elf  "sinDecFreqButtonControl.hex"
	@echo 'Finished building: $@'
	@echo ' '

sinDecFreqButtonControl.eep: sinDecFreqButtonControl.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex sinDecFreqButtonControl.elf  "sinDecFreqButtonControl.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sinDecFreqButtonControl.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t sinDecFreqButtonControl.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) sinDecFreqButtonControl.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
