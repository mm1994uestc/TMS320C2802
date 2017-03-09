
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
extern int16 parameter[60];
void InitGpio(void)
{
   EALLOW; //执行asm(" EALLOW")允许设置GPIO寄存器
#if 0
   GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   //As PWM
   GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  

   GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    //Enable pull-up
   GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   //As PWM
   GpioCtrlRegs.GPADIR.bit.GPIO1 = 1; 

   GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Disable pull-up on GPIO2 (EPWM2A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
   GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;

   GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;
   GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   //As PWM
   GpioCtrlRegs.GPADIR.bit.GPIO3 = 1; 

   GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;
   GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;
   GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;  

   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;
   GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;
   GpioCtrlRegs.GPADIR.bit.GPIO5 = 1; 

   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;
   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
  
   GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
#endif

   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0; //Timer cycle control LED
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;

   GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0; //While cycle control LED
   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;

   GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;   // Enable pullup on GPIO22(使能上拉GPIO22端口) RELAY继电器的硬件连接端口 RLY1---GPIO-22
   GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;  // GPIOA_MUX2:Bit12 & Bit13 = 00 ==> GPIO22 (I/O), General purpose I/O 22 (default)
   GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;   // Configures the GPIO22 pin as an output
   GpioDataRegs.GPACLEAR.bit.GPIO22 = 1;   // Set the output value of GPIO22 = 0(Clear the GPIO)

   GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0; //Output Port(ADC_Voltage Present LED)
   GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO24 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO24 = 1;

#if 0
   GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;
   
   GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO17 = 1;
   
   GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO18 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO18 = 1;
   
   GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;
   
   GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;
     
   GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;
  
   GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO26 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;   // Load output latch
  
   GpioCtrlRegs.GPAPUD.bit.GPIO28 =   0;
   GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;
   GpioCtrlRegs.GPAMUX2.bit.GPIO28 =  1;
   GpioCtrlRegs.GPAPUD.bit.GPIO29 =   0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO29 =  1;

   GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;
   GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;
   GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;
   GpioDataRegs.GPASET.bit.GPIO31 = 1;


   GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;
   GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
   GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
   GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
#endif
   EDIS;
}
	
