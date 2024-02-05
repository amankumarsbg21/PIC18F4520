/*
 * File:   SWITCH_LED.c
 * Author: aman6
 *
 * Created on 5 February, 2024, 11:54 PM
 */


#include <xc.h>
#pragma config OSC =HS
#pragma config WDT = OFF
#define LED RD0
int count =0;
int i=0;
void __interrupt(high_priority)isr(void){
    if(INT0IF){
        INT0IF=0;
        if(count<5){
            LED=~LED;
            count++;
        }
        
    }
    if(TMR0IF){
        TMR0IF=0;
        if(i==0)i++;
        else{
            i=0;
            count=0;
        }
        TMR0ON=0;
        TMR0H=0x41;
        TMR0L=0x43;
        TMR0ON=1;
        
        
    }
}
void main(void) {
    ADCON1=0x0F;
    TRISD0=0;
    TRISB0=1;
    T0CON=0x07;
    TMR0H=0x41;
    TMR0L=0x43;
    INTCON=0xF0;
    TMR0ON=1;
    
    while(1);
    
    
}
