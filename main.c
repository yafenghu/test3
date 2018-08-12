/***************************************************
�����ܣ���̬��ʾ���֡�welcome��
----------------------------------------------------
����˵�����۲�Һ����ʾ
****************************************************/
#include  <msp430.h>
#include  "Cry1602.h"
#include  "Cry1602.c"

uchar *s1 = "welcome!";

void main( void )
{
  
    /*�������г���ر����е�IO��*/
    P1DIR = 0XFF;P1OUT = 0XFF;
    P2DIR = 0XFF;P2OUT = 0XFF;
    P3DIR = 0XFF;P3OUT = 0XFF;
    P4DIR = 0XFF;P4OUT = 0XFF;
    P5DIR = 0XFF;P5OUT = 0XFF;
    P6DIR = 0XFF;P6OUT = 0XFF;  
  
    uchar i;
    WDTCTL = WDT_ADLY_250;               //�����ʱ������ʱ16ms
    P6DIR |= BIT2;P6OUT |= BIT2;         //�رյ�ƽת��
    LcdReset();
    DispStr(4,0,s1);
    LocateXY(0,9);                      //ȷ��д���ַ�����ʾλ��
    LcdWriteCommand(0x07, 1);           //������ʾ����
    for(i = 12; i > 0; i--) 
    {
        LcdWriteData(0x20);
        //��ʱ250ms
        IFG1 &= ~WDTIFG;
        while(!(IFG1 & WDTIFG));
        IFG1 &= ~WDTIFG; 
    }
    while(1)
    {
        LcdWriteCommand(0x05, 1);           //��ʾ��������
        
        for(i = 24; i > 0; i--)  
        {
            LcdWriteData(0x20);
            //��ʱ250ms
            IFG1 &= ~WDTIFG;
            while(!(IFG1 & WDTIFG));
            IFG1 &= ~WDTIFG; 
        }
    
        
        LcdWriteCommand(0x07, 1);           //������ʾ����
        
        for(i = 24; i > 0; i--)
        {
            LcdWriteData(0x20);
            //��ʱ250ms
            IFG1 &= ~WDTIFG;
            while(!(IFG1 & WDTIFG));
            IFG1 &= ~WDTIFG; 
        }
    }    
}
