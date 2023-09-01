################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/STEPPERMOTOR/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/KPD/subdir.mk
-include HAL/CLCD/subdir.mk
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
Conter_using_SSD.lss \

FLASH_IMAGE += \
Conter_using_SSD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Conter_using_SSD.elf secondary-outputs

# Tool invocations
Conter_using_SSD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Conter_using_SSD.map -mmcu=atmega32 -o "Conter_using_SSD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Conter_using_SSD.lss: Conter_using_SSD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Conter_using_SSD.elf  >"Conter_using_SSD.lss"
	@echo 'Finished building: $@'
	@echo ' '

Conter_using_SSD.hex: Conter_using_SSD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Conter_using_SSD.elf  "Conter_using_SSD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Conter_using_SSD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Conter_using_SSD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Conter_using_SSD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
