/*
 * 
 * File:   main.c
 * Author: Panki
 *
 * Created on 19. Oktober 2016, 13:41
 */

//Selfdefined
#define USE_OR_MASK
#include <outcompare.h>
#include <timer.h>

#define FOSC 10000000
#define FCY (FOSC/2)

#include "header.h"

#include <p24fj128ga010.h>

#define BAR0  0x00
#define BAR1  0x01
#define BAR2  0x02
#define BAR3  0x03
#define BAR4  0x04

void OpenOC1(unsigned int config, unsigned int value1, unsigned int value2);

char SetDCOC1PWM(unsigned int dutycycle);

void PlayTone(int freq) {
  int period = (int) 4000000/freq;
  PR2 = period;
}

int main(void) {

 //OpenOC1( OC_IDLE_CON & OC_TIMER2_SRC & OC_CONTINUE_PULSE, 800, 400);
 //SetPulseOC1(400, 800);
 
    
//OpenOC1(OC_IDLE_CON | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, 256,128);


 OC1CON = 0x0006; 
 
 OC1R =  512;
 OC1RS = 1024;
 //ConfigIntOC1(OC_INT_OFF);
 T2CON = 0x8000;
 
 //while (1){}
 LEDPIN1 = OUTPUT;
 LEDPIN2 = OUTPUT;
 LEDPIN3 = OUTPUT;
 LEDPIN4 = OUTPUT;
 LEDPIN5 = OUTPUT;
 LEDPIN6 = OUTPUT;
 LEDPIN7 = OUTPUT;
 LEDPIN8 = OUTPUT;
    
 LCD_Initialize();
 CG_Build();
 
 if( SetDCOC1PWM(512) == -1){
     LCD_PutString("ERROR", 5);
     while(1){}   
 }

    while(1)
  {    
        
        
        PR2 = 9090;
        __delay_ms(500);
        PlayTone(329);
        __delay_ms(500);
        PlayTone(349);
        __delay_ms(500);
        PlayTone(392);
        __delay_ms(500);
        PlayTone(440);
        __delay_ms(500);
        PlayTone(1);
        __delay_ms(50);
        PlayTone(440);
        __delay_ms(500);
      /*  PR2 = 10000;
        LED1 = ON;
        LCD_PutChar(BAR0);
        __delay_ms(1000);
        
        PR2 = 1000;
        LED2 = ON;
        LCD_PutChar(BAR1);
        __delay_ms(1000);
        
        PR2 = 3000;
        LED3 = ON;
        LCD_PutChar(BAR2);
        __delay_ms(1000);
        
        PR2 = 500;
        LED4 = ON;
        __delay_ms(1000);
        
        PR2 = 6000;
        LED5 = ON;
        LCD_PutChar(BAR3);
        __delay_ms(1000);
        
        LED6 = ON;
        __delay_ms(1000);
        
        LED7 = ON;
        LCD_PutChar(BAR4);
        __delay_ms(1000);
        
        LED8 = ON;
        __delay_ms(1000);
        
        LED1 = OFF;
        LED2 = OFF;
        LED3 = OFF;
        LED4 = OFF;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = OFF;
        LED8 = OFF;
        LCD_ClearScreen();
        __delay_ms(350); */
    }
  return 0;
}