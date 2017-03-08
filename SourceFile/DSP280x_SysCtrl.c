// TI File $Revision: /main/6 $
// Checkin $Date: August 2, 2006   16:58:31 $
//###########################################################################
//
// FILE:   DSP280x_SysCtrl.c
//
// TITLE:  DSP280x Device System Control Initialization & Support Functions.
//
// DESCRIPTION:
//
//         Example initialization of system resources.
//
//###########################################################################
// $TI Release: DSP280x, DSP2801x Header Files V1.41 $
// $Release Date: August 7th, 2006 $
//###########################################################################


#include "DSP280x_Device.h"     // Headerfile Include File
#include "DSP280x_Examples.h"   // Examples Include File

// Functions that will be run from RAM need to be assigned to 
// a different section.  This section will then be mapped to a load and 
// run address using the linker cmd file.

#pragma CODE_SECTION(InitFlash, "ramfuncs");

void InitSysCtrl(void)
{

   DisableDog();
   
   InitPll(DSP28_PLLCR,DSP28_CLKINDIV);

   InitPeripheralClocks();
}



void InitFlash(void)
{
   EALLOW;
   //Enable Flash Pipeline mode to improve performance
   //of code executed from Flash.
   FlashRegs.FOPT.bit.ENPIPE = 1;
   
   //                CAUTION
   //Minimum waitstates required for the flash operating
   //at a given CPU rate must be characterized by TI. 
   //Refer to the datasheet for the latest information.  

   //Set the Paged Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 3;

   //Set the Random Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.RANDWAIT = 3;
   
   //Set the Waitstate for the OTP
   FlashRegs.FOTPWAIT.bit.OTPWAIT = 5;
   
   //                CAUTION
   //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;       
   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;   
   EDIS;

   //Force a pipeline flush to ensure that the write to 
   //the last register configured occurs before returning.  

   asm(" RPT #7 || NOP");
}	


//---------------------------------------------------------------------------
// Example: ServiceDog: 
//---------------------------------------------------------------------------
// This function resets the watchdog timer.
// Enable this function for using ServiceDog in the application 

void ServiceDog(void)
{
    EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
}

//---------------------------------------------------------------------------
// Example: DisableDog: 
//---------------------------------------------------------------------------
// This function disables the watchdog timer.

void DisableDog(void)
{
    EALLOW; //设置寄存器1的C6位，从而允许设置受EALLOW保护的模块的寄存器：GPIO寄存器，MUX寄存器等等(下面的SysCtrlRegs的所有寄存器都受EALLOW保护，设置前要关掉保护)
    SysCtrlRegs.WDCR= 0x0068;
    //SysCtrlRegs系统控制寄存器，由结构体SYS_CTRL_REGS定义，WDCR为Uint16型成员变量，手册上的地址是0x7029，装载的值是0x0068=0000 0000 0110 1000，设置Bit6=1 Disable Watchdog
    EDIS; //关闭DSP部分重要寄存器的设置权限，将寄存器的值禁止写入，保护起来
}

//---------------------------------------------------------------------------
// Example: InitPll: 
//---------------------------------------------------------------------------
// This function initializes the PLLCR register.

void InitPll(Uint16 val, Uint16 clkindiv)
{
   volatile Uint16 iVol;   

   // Make sure the PLL is not running in limp mode
   if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 0)
   {
      // Missing external clock has been detected
      // Replace this line with a call to an appropriate
      // SystemShutdown(); function. 
      asm("        ESTOP0");
   }

   // CLKINDIV MUST be 0 before PLLCR can be changed from
   // 0x0000. It is set to 0 by an external reset XRSn
   if (SysCtrlRegs.PLLSTS.bit.CLKINDIV != 0)
   {
       SysCtrlRegs.PLLSTS.bit.CLKINDIV = 0;
   }
   
   // Change the PLLCR
   if (SysCtrlRegs.PLLCR.bit.DIV != val)
   {
       
      EALLOW;
      // Before setting PLLCR turn off missing clock detect logic
      SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;
      SysCtrlRegs.PLLCR.bit.DIV = val;
      EDIS;
   
      DisableDog();
   
      while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1) 
      {
	      // Uncomment to service the watchdog
          // ServiceDog();
      }

      EALLOW;
      SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
      SysCtrlRegs.PLLSTS.bit.CLKINDIV != clkindiv;      
      EDIS;   
    }
}


void InitPeripheralClocks(void)
{
   EALLOW;

// HISPCP/LOSPCP prescale register settings, normally it will be set to default values
   SysCtrlRegs.HISPCP.all = 0x001 ;   //50MHZ
   SysCtrlRegs.LOSPCP.all = 0x002;   //25MHZ

// XCLKOUT to SYSCLKOUT ratio.  By default XCLKOUT = 1/2 SYSCLKOUT
   SysCtrlRegs.XCLK.bit.XCLKOUTDIV=10 ;
      	

   SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;    // ADC
   SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;   // I2C
   SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;  // eCAP1
   SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;  // eCAP2
   SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;  // ePWM1
   SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;  // ePWM2
   SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;  // ePWM3
   SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;   // SCI-A
   SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;   // SPI-A

   if(DevEmuRegs.PARTID.bit.PARTNO != PARTNO_28015 &&
      DevEmuRegs.PARTID.bit.PARTNO != PARTNO_28016)
   {
      SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 1;  // eQEP1
      SysCtrlRegs.PCLKCR0.bit.SPIBENCLK = 1;   // SPI-B     
   }

   if(DevEmuRegs.PARTID.bit.PARTNO != PARTNO_2801 &&
      DevEmuRegs.PARTID.bit.PARTNO != PARTNO_2802)
   {
	   SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;  // ePWM4
   }
    
   if(DevEmuRegs.PARTID.bit.PARTNO != PARTNO_28015)
   {
      SysCtrlRegs.PCLKCR0.bit.ECANAENCLK=1;    // eCAN-A  
   }
   
   if(DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2809 || 
      DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2808 ||
      DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2806 )
   {
	   SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 1;  // eCAP3
	   SysCtrlRegs.PCLKCR1.bit.ECAP4ENCLK = 1;  // eCAP4
	   SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;  // ePWM5
	   SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;  // ePWM6
	   SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 1;   // SCI-B
	   SysCtrlRegs.PCLKCR0.bit.SPICENCLK = 1;   // SPI-C
	   SysCtrlRegs.PCLKCR0.bit.SPIDENCLK = 1;   // SPI-D
	   SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;  // eQEP2
 
   }
   if(DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2808 ||
      DevEmuRegs.PARTID.bit.PARTNO == PARTNO_2809)
   {  
	   SysCtrlRegs.PCLKCR0.bit.ECANBENCLK=1;    // eCAN-B
   }

   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;       // Enable TBCLK within the ePWM  
                           
   EDIS;
}

	
//===========================================================================
// End of file.
//===========================================================================
