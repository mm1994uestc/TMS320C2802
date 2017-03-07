
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
extern int16 parameter[60];
void InitGpio(void)
{
   EALLOW; 
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

   GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   //As PWM
   GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;  
   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    //Enable pull-up
   GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   //As PWM
   GpioCtrlRegs.GPADIR.bit.GPIO5 = 1; 

//===========================================================================
// END PWM-GPIO
//===========================================================================
   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Disable pull-up on GPIO2 (EPWM2A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;   // Configure GPIO2 as EPWM2A
   GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
//===========================================================================
// END LED-GPIO-DSP-PIN56
//===========================================================================
  
   GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;   // Configure GPIO2 as EPWM2A
   GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
//===========================================================================
// END OUT-OE-GPIO-U4-U10-MC74LVXC3245-22PIN
//===========================================================================
 //===========================================================================
// END 12-15-GPIO-EMPTY
//===========================================================================
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Disable pull-up on GPIO2 (EPWM2A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;   // Configure GPIO2 as EPWM2A
   GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;

    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Disable pull-up on GPIO2 (EPWM2A)
   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;   // Configure GPIO2 as EPWM2A
   GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;


 // GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;   // Enable pullup on GPIO6  //RELAY
  // GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0;  // GPIO6 = GPIO6
  // GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;   // GPIO6 = output
  // GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;   // Load output latch
   
  // GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;   // Enable pullup on GPIO6  //RELAY
  // GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;  // GPIO6 = GPIO6
  // GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;   // GPIO6 = output
   //GpioDataRegs.GPACLEAR.bit.GPIO17 = 1;   // Load output latch
   
   // GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;   // Enable pullup on GPIO6  //RELAY
   //GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;  // GPIO6 = GPIO6
   //GpioCtrlRegs.GPADIR.bit.GPIO18 = 1;   // GPIO6 = output
   //GpioDataRegs.GPACLEAR.bit.GPIO18 = 1;   // Load output latch
   
   GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;   // Enable pullup on GPIO6  //RELAY
   GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;  // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;   // Load output latch
   
    //GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pullup on GPIO6  //RELAY
   //GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;  // GPIO6 = GPIO6
   //GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;   // GPIO6 = output
   //GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;   // Load output latch
     
   GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pullup on GPIO6  //RELAY
   GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;  // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;   // Load output latch


   GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;   // Enable pullup on GPIO6  //RELAY
   GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;  // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO24 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO24 = 1;   // Load output latch

    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;   // Enable pullup on GPIO6  //RELAY
   GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;  // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO22 = 1;   // Load output latch
 //===========================================================================
// END LED1-RLY1-LED2-RLY2-LED3-FAN2-FAN1
//===========================================================================
  
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;   // Enable pullup on GPIO6  //RELAY
   GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;  // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO26 = 1;   // GPIO6 = output
   GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;   // Load output latch
 //===========================================================================
// END IN_OE
//===========================================================================
  
   GpioCtrlRegs.GPAPUD.bit.GPIO28 =   0;   // Enable pullup on GPIO14      
   GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3; // Asynch input
   GpioCtrlRegs.GPAMUX2.bit.GPIO28 =  1;  // GPIO14 = SCIRXDA
   GpioCtrlRegs.GPAPUD.bit.GPIO29 =   0;   // Enable pullup on GPIO15         
   GpioCtrlRegs.GPAMUX2.bit.GPIO29 =  1;  // GPIO15 = SCITXDA    
 //===========================================================================
// END SCIRX_TX
//===========================================================================    
   GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;   // Enable pullup on GPIO6  //RELAY
   GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;  // GPIO6 = GPIO6
   GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;   // GPIO6 = output
   GpioDataRegs.GPASET.bit.GPIO31 = 1;   // Load output latch


  // GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;   // Enable pullup on GPIO6  //RELAY
  // GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;  // GPIO6 = GPIO6
  // GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;   // GPIO6 = output
  // GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;   // Load output latch

//===========================================================================
// END CANTX-MAX485-ENABLE
//===========================================================================
   EDIS;
}
	
