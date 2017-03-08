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
	InitCpuTimers();//��ʼ��CPU��ʱ��
	EALLOW;
	PieVectTable.TINT0 = &TINT0_ISR;//��ʱ��0�ж�ʸ��
	EDIS;

	ConfigCpuTimer(&CpuTimer0, 100, 1000000);//���ö�ʱ���ж�ʱ��

	StartCpuTimer0();//��ʼCPU�ж�

	IER |= M_INT1;//ʹ��INT1�ж�

	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
 // Enable TINT0 in the PIE: Group 1 interrupt 7

	EINT;   // Enable Global interrupt INTM ����ȫ���ж�
    ERTM;   // Enable Global realtime interrupt DBGM����ȫ��ʵʱ�ж�DBGM
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
 interrupt void TINT0_ISR(void)//CPU��ʱ��0�жϷ����ӳ���
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
