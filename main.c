/***************************************************
程序功能：动态显示文字“welcome”
----------------------------------------------------
测试说明：观察液晶显示
****************************************************/
#include  <msp430.h>
#include  "Cry1602.h"
#include  "Cry1602.c"

uchar *s1 = "welcome!";

void main( void )
{
  
    /*下面六行程序关闭所有的IO口*/
    P1DIR = 0XFF;P1OUT = 0XFF;
    P2DIR = 0XFF;P2OUT = 0XFF;
    P3DIR = 0XFF;P3OUT = 0XFF;
    P4DIR = 0XFF;P4OUT = 0XFF;
    P5DIR = 0XFF;P5OUT = 0XFF;
    P6DIR = 0XFF;P6OUT = 0XFF;  
  
    uchar i;
    WDTCTL = WDT_ADLY_250;               //间隔定时器，定时16ms
    P6DIR |= BIT2;P6OUT |= BIT2;         //关闭电平转换
    LcdReset();
    DispStr(4,0,s1);
    LocateXY(0,9);                      //确定写入字符的显示位置
    LcdWriteCommand(0x07, 1);           //整体显示左移
    for(i = 12; i > 0; i--) 
    {
        LcdWriteData(0x20);
        //延时250ms
        IFG1 &= ~WDTIFG;
        while(!(IFG1 & WDTIFG));
        IFG1 &= ~WDTIFG; 
    }
    while(1)
    {
        LcdWriteCommand(0x05, 1);           //显示整体右移
        
        for(i = 24; i > 0; i--)  
        {
            LcdWriteData(0x20);
            //延时250ms
            IFG1 &= ~WDTIFG;
            while(!(IFG1 & WDTIFG));
            IFG1 &= ~WDTIFG; 
        }
    
        
        LcdWriteCommand(0x07, 1);           //整体显示左移
        
        for(i = 24; i > 0; i--)
        {
            LcdWriteData(0x20);
            //延时250ms
            IFG1 &= ~WDTIFG;
            while(!(IFG1 & WDTIFG));
            IFG1 &= ~WDTIFG; 
        }
    }    
}
