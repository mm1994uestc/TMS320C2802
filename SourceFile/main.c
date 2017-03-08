#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

void delay(int num);
interrupt void TINT0_ISR(void);
int count;
void main(void)
{
   count=0;
   InitSysCtrl();
   InitGpio();
   DINT;
   InitPieCtrl();
   IER = 0x0000;
   IFR = 0x0000;
   InitPieVectTable();
//--------------------------------------------------
	InitCpuTimers();//初始化CPU定时器
	EALLOW;
	PieVectTable.TINT0 = &TINT0_ISR;//定时器0中断矢量
	EDIS;

	ConfigCpuTimer(&CpuTimer0, 100, 1000000);//配置定时器中断时长

	StartCpuTimer0();//开始CPU中断

	IER |= M_INT1;//使能INT1中断

	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
 // Enable TINT0 in the PIE: Group 1 interrupt 7

	EINT;   // Enable Global interrupt INTM 开放全局中断
    ERTM;   // Enable Global realtime interrupt DBGM开放全局实时中断DBGM
    while(1)
    {
    	GpioDataRegs.GPATOGGLE.bit.GPIO15 = 1;
    	delay(100);
    	GpioDataRegs.GPATOGGLE.bit.GPIO15 = 0;
    	delay(100);
    }
}
void delay(int num)
{
    while(num--)
    {
        long i = 1000;
        while(i--);
    }

}
 interrupt void TINT0_ISR(void)//CPU定时器0中断服务子程序
{
	//GpioDataRegs.GPATOGGLE.bit.GPIO24 = 1; //LED1
	//GpioDataRegs.GPATOGGLE.bit.GPIO15 = 1; //LED2
	GpioDataRegs.GPATOGGLE.bit.GPIO12 = 1; //LED3
	count++;
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
 // CpuTimer0Regs.TCR.bit.TIF=1;
//  PieCtrlRegs.PIEACK.all |= PIEACK_GROUP1;
//  EINT;
}
