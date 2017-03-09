// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   11:11:30 $
//###########################################################################
//
// FILE:	DSP280x_Adc.c
//
// TITLE:	DSP280x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP280x C/C++ Header Files V1.70 $
// $Release Date: July 27, 2009 $
//###########################################################################

#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

#define ADC_usDELAY  5000L

//---------------------------------------------------------------------------
// InitAdc: 
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
// PLEASE NOTE, ADC INIT IS DIFFERENT ON 281x vs 280x DEVICES!!!
//
void InitAdc(void)
{  
    //extern void DSP28x_usDelay(Uint32 Count);

    // To powerup the ADC the ADCENCLK bit should be set first to enable
    // clocks, followed by powering up the bandgap, reference circuitry, and ADC core.
    // Before the first conversion is performed a 5ms delay must be observed 
	// after power up to give all analog circuits time to power up and settle

    // Please note that for the delay function below to operate correctly the 
	// CPU_CLOCK_SPEED define statement in the DSP280x_Examples.h file must 
	// contain the correct CPU clock period in nanoseconds. 
    /* Introduction for The ADC module found on DSP280x_
     *ADC有16个通道，可以配置成为两组独立的8通道增强型ePWM模块使用，这两组独立的8通道ePWM可以通过cascaded(级联)构成16通道的ePWM模块
     *尽管有这么多的通道，但是ADC中只有一个AD转换器convert，控制寄存器Table
     *
     *RESET SUSMOD ACQ_PS CPS CONT_RUN SEQ_CASC
     *由于TMS320C2802的ADC通道引脚是独立的，所以不存在配置GPIO复用功能的问题，直接配置好相应的控制寄存器就可以了
     */
    EALLOW;
#if 1
    AdcRegs.ADCTRL1.bit.RESET = 1; //Reset the ADC Module
    AdcRegs.ADCTRL1.bit.SUSMOD = 3; //Mode 3. Sequencer and other wrapper logic stops immediately on emulation suspend
    AdcRegs.ADCTRL1.bit.ACQ_PS = 0; //The width of SOC pulse is ADCTRL1[11:8] + 1 times the ADCLK period
    AdcRegs.ADCTRL1.bit.CPS = 0; //ADCCLK = Fclk/1  Note: Fclk = Prescaled HSPCLK (ADCCLKPS[3:0])
    AdcRegs.ADCTRL1.bit.CONT_RUN = 0; //Start-stop mode
    AdcRegs.ADCTRL1.bit.SEQ_OVRD = 1; //Enabled - Overrides the sequencer from wrapping around at the end of conversions set by MAX_CONVn
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 1; //Dual-sequencer mode. SEQ1 and SEQ2 operate as one 16-state sequencers

    AdcRegs.ADCTRL2.bit.RST_SEQ2 = 1; //Immediately resets SEQ2 to an initial "pretriggered" state
    AdcRegs.ADCTRL2.bit.SOC_SEQ2 = 0; //Clears a pending SOC trigger
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 0; //Interrupt request by INT_SEQ1 is disabled
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 0; //Interrupt request by INT_SEQ2 is disabled
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0; //INT_SEQ1 is set at the end of every SEQ1 sequence
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ2 = 0; //INT_SEQ2 is set at the end of every SEQ2 sequence
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 0; //SEQ1 cannot be started by ePWMx SOCA trigger
    AdcRegs.ADCTRL2.bit.EXT_SOC_SEQ1 = 0; //No action(External signal start-of-conversion bit for SEQ1)
    AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2 = 0; //SEQ2 cannot be started by ePWMx SOCB trigger
    AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ = 0; //No action

    //AdcRegs.ADCTRL3.all = 0x00E0;
    AdcRegs.ADCTRL3.bit.ADCCLKPS = 0;
    AdcRegs.ADCTRL3.bit.ADCBGRFDN = 3; // Power up bandgap/reference/ADC circuits 可以使用all成员变量来初始化起始地址之后的所有变量
    AdcRegs.ADCTRL3.bit.ADCPWDN = 1;  //The analog circuitry inside the core is powered up
    AdcRegs.ADCTRL3.bit.SMODE_SEL = 0; //Sequential sampling mode is selected

    AdcRegs.ADCREFSEL.bit.REF_SEL = 0; //Internal reference selected (default)

    AdcRegs.ADCMAXCONV.all = 0; //Number of Conversions = 1(只转换一次，存储的位置一直是ADCREFSEL0结果寄存器)

    AdcRegs.ADCCHSELSEQ1.all = 5; //All Channel select to be ADCINA5
    AdcRegs.ADCCHSELSEQ2.all = 5;
	AdcRegs.ADCCHSELSEQ3.all = 5;
    AdcRegs.ADCCHSELSEQ4.all = 5;
#endif
    EDIS;
    //DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels
}	

//===========================================================================
// End of file.
//===========================================================================
