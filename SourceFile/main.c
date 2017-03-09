#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

#define ADCLO 0

void delay(int num);
interrupt void TINT0_ISR(void);

void main(void)
{
   int count=0;
   float ADC_Voltage=0.0;
   InitSysCtrl(); //通过设置WCDR寄存器的Bit6=1，关闭了WCDR Watchdog看门狗
   InitGpio(); //初始化了GPIOA和GPIOB的控制寄存器，设置了GPIOA.Bit0等引脚为ePWM模式或者普通GPIO模式，设置了GPIO的输入输出模式
   DINT; //asm(" setc INTM")置位INTM为1，Disable Interrupter
   InitPieCtrl(); // Disable the PIE，Clear all PIEIER registers
   IER = 0x0000; //定义在DSP280x_Device.h文件当中，数据类型：extern cregister volatile unsigned int IER;
   IFR = 0x0000; //定义在DSP280x_Device.h文件当中，数据类型：extern cregister volatile unsigned int IFR;
   InitPieVectTable(); // Enable the PIE Vector Table
//--------------------------------------------------
	InitCpuTimers();//初始化CPU定时器
	EALLOW;
	PieVectTable.TINT0 = &TINT0_ISR;//定时器0中断矢量
	EDIS;

	ConfigCpuTimer(&CpuTimer0, 100, 1000000);//配置定时器中断时长:struct CPUTIMER_VARS CpuTimer0;

	InitAdc(); // Initial The Adc with the function InitAdc(),The GPIO Set to be the ADC_Channel is M_CL=ADC-A5
	delay(50);
	// 电路原理图

	StartCpuTimer0();//开始CPU中断

	IER |= M_INT1;//使能INT1中断

	PieCtrlRegs.PIEIER1.bit.INTx7 = 1; // Enable TINT0 in the PIE: Group 1 interrupt 7

	EINT;   // Enable Global interrupt INTM 开放全局中断
    ERTM;   // Enable Global realtime interrupt DBGM开放全局实时中断DBGM
    while(1)
    {
    	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1; //Immediately reset sequencer to state CONV00
    	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1; //S/W - Software writing a 1 to this bit
    	ADC_Voltage = ADCLO+(AdcMirror.ADCRESULT0)*3.0/4096; //The formulation to calculate the input ADC_Voltage,Use the mirror result we do not need to right shift the ADC_value
    	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1; //Immediately reset sequencer to state CONV00
    	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 0; //Clears a pending SOC trigger
    	delay(100);
    	if(0 == count%10)
    	{
    		count = 0;
    		ADC_Voltage = ADC_Voltage/10.0;
    		if(ADC_Voltage >= 1.5){
    			GpioDataRegs.GPASET.bit.GPIO15 = 1;
    			//GpioDataRegs.GPACLEAR.bit.GPIO24 = 1; //Remember to init the GPIO Port as Output
    		}
    		else{
    			GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;
    			//GpioDataRegs.GPASET.bit.GPIO24 = 1; //The LED on the port GPIO24 is Broken!
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
 interrupt void TINT0_ISR(void)//CPU定时器0中断服务子程序
{
	GpioDataRegs.GPATOGGLE.bit.GPIO12 = 1; //LED3：Toggle的意思是切换的意思，相当于执行一次切换一次状态，相当于翻转寄存器
	GpioDataRegs.GPATOGGLE.bit.GPIO22 = 1; //配置GPIO22端口为翻转模式，控制继电器定时关断
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; //清除中断标志位？
}
