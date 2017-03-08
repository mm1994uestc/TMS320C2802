#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

#define ADCLO 0

void delay(int num);
interrupt void TINT0_ISR(void);

void main(void)
{
   int count=0;
   float ADC_Voltage=0.0;
   InitSysCtrl(); //ͨ������WCDR�Ĵ�����Bit6=1���ر���WCDR Watchdog���Ź�
   InitGpio(); //��ʼ����GPIOA��GPIOB�Ŀ��ƼĴ�����������GPIOA.Bit0������ΪePWMģʽ������ͨGPIOģʽ��������GPIO���������ģʽ
   DINT; //asm(" setc INTM")��λINTMΪ1��Disable Interrupter
   InitPieCtrl(); // Disable the PIE��Clear all PIEIER registers
   IER = 0x0000; //������DSP280x_Device.h�ļ����У��������ͣ�extern cregister volatile unsigned int IER;
   IFR = 0x0000; //������DSP280x_Device.h�ļ����У��������ͣ�extern cregister volatile unsigned int IFR;
   InitPieVectTable(); // Enable the PIE Vector Table
//--------------------------------------------------
	InitCpuTimers();//��ʼ��CPU��ʱ��
	EALLOW;
	PieVectTable.TINT0 = &TINT0_ISR;//��ʱ��0�ж�ʸ��
	EDIS;

	ConfigCpuTimer(&CpuTimer0, 100, 1000000);//���ö�ʱ���ж�ʱ��:struct CPUTIMER_VARS CpuTimer0;

	//InitAdc(); // Initial The Adc with the function InitAdc(),The GPIO Set to be the ADC_Channel is M_CL=ADC-A5
	// ��·ԭ��ͼ

	StartCpuTimer0();//��ʼCPU�ж�

	IER |= M_INT1;//ʹ��INT1�ж�

	PieCtrlRegs.PIEIER1.bit.INTx7 = 1; // Enable TINT0 in the PIE: Group 1 interrupt 7

	EINT;   // Enable Global interrupt INTM ����ȫ���ж�
    ERTM;   // Enable Global realtime interrupt DBGM����ȫ��ʵʱ�ж�DBGM
    while(1)
    {
    	GpioDataRegs.GPASET.bit.GPIO15 = 1;
    	delay(800);
    	GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;
    	delay(800);
    	ADC_Voltage = ADCLO+(AdcMirror.ADCRESULT5)*3.0/4096; //The formulation to calculate the input ADC_Voltage
    	if(0 == count%10)
    	{
    		count = 0;
    		ADC_Voltage = ADC_Voltage/3.0;
    		if(ADC_Voltage <= 1.5){
    			GpioDataRegs.GPACLEAR.bit.GPIO24 = 1; //Remember to init the GPIO Port as Output
    		}
    		else{
    			GpioDataRegs.GPASET.bit.GPIO24 = 1;
    		}
    		ADC_Voltage = 0;
    	}
    	count++;
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
	GpioDataRegs.GPATOGGLE.bit.GPIO12 = 1; //LED3��Toggle����˼���л�����˼���൱��ִ��һ���л�һ��״̬���൱�ڷ�ת�Ĵ���
	GpioDataRegs.GPATOGGLE.bit.GPIO22 = 1; //����GPIO22�˿�Ϊ��תģʽ�����Ƽ̵�����ʱ�ض�
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; //����жϱ�־λ��
}
