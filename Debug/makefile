################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./SourceFile/DSP280x_CodeStartBranch.obj" \
"./SourceFile/DSP280x_CpuTimers.obj" \
"./SourceFile/DSP280x_DefaultIsr.obj" \
"./SourceFile/DSP280x_GlobalVariableDefs.obj" \
"./SourceFile/DSP280x_Gpio.obj" \
"./SourceFile/DSP280x_PieCtrl.obj" \
"./SourceFile/DSP280x_PieVect.obj" \
"./SourceFile/DSP280x_SysCtrl.obj" \
"./SourceFile/DSP280x_usDelay.obj" \
"./SourceFile/main.obj" \
"../SourceFile/DSP280x_Headers_nonBIOS.cmd" \
"../SourceFile/F2802.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include SourceFile/subdir_vars.mk
-include SourceFile/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TMS320C2802.out \

EXE_OUTPUTS__QUOTED += \
"TMS320C2802.out" \

BIN_OUTPUTS += \
TMS320C2802.hex \

BIN_OUTPUTS__QUOTED += \
"TMS320C2802.hex" \


# All Target
all: TMS320C2802.out

# Tool invocations
TMS320C2802.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt -g --display_error_number --diag_warning=225 --diag_wrap=off -z -m"TMS320C2802.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/lib" -i"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="TMS320C2802_linkInfo.xml" --rom_model -o "TMS320C2802.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

TMS320C2802.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/hex2000"  -o "TMS320C2802.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "SourceFile\DSP280x_CpuTimers.d" "SourceFile\DSP280x_DefaultIsr.d" "SourceFile\DSP280x_GlobalVariableDefs.d" "SourceFile\DSP280x_Gpio.d" "SourceFile\DSP280x_PieCtrl.d" "SourceFile\DSP280x_PieVect.d" "SourceFile\DSP280x_SysCtrl.d" "SourceFile\main.d" 
	-$(RM) "SourceFile\DSP280x_CodeStartBranch.obj" "SourceFile\DSP280x_CpuTimers.obj" "SourceFile\DSP280x_DefaultIsr.obj" "SourceFile\DSP280x_GlobalVariableDefs.obj" "SourceFile\DSP280x_Gpio.obj" "SourceFile\DSP280x_PieCtrl.obj" "SourceFile\DSP280x_PieVect.obj" "SourceFile\DSP280x_SysCtrl.obj" "SourceFile\DSP280x_usDelay.obj" "SourceFile\main.obj" 
	-$(RM) "SourceFile\DSP280x_CodeStartBranch.d" "SourceFile\DSP280x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

