/*
 * 
 * File:   main.c
 * Author: Panki
 *
 * Created on 19. Oktober 2016, 13:41
 */

//Selfdefined
#define USE_OR_MASK

#define SET_CONFIG_BITS
#include "header.h"
#undef SET_CONFIG_BITS

#include <outcompare.h>
#include <timer.h>


//#include "header.h"
#include "lib/rtttl.h"

#include <p24fj128ga010.h>

#define BAR0  0x00
#define BAR1  0x01
#define BAR2  0x02
#define BAR3  0x03
#define BAR4  0x04

void OpenOC1(unsigned int config, unsigned int value1, unsigned int value2);

char SetDCOC1PWM(unsigned int dutycycle);

/* void PlayTone(int freq) {
  int period = (int) 4000000/freq;
  PR2 = period;
}

unsigned int note_freq[]={
0x0000, // silent
63441,63559,63670,63775,63874,63967,64055,64138,64217,64291,64360,64426, // A= 220Hz   (o=4)
64489,64547,64603,64655,64705,64751,64795,64837,64876,64913,64948,64981, // A= 440Hz   (o=5)
65012,65042,65069,65096,65120,65144,65166,65187,65206,65225,65242,65259, // A= 880Hz   (o=6)
65274,65289,65303,65316,65328,65340,65351,65361,65371,65380,65389,65397, // A= 1.76KHz (o=7)
65405,65412,65419,65426,65432,65438,65443,65449,65454,65458,65463,65467  // A= 3.52KHz (o=8)
}; */

char AnotherO[]={"AnotherO:d=16,o=5,b=80:32p,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#.6,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#.6,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#.6,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#6"};

int main(void) {

OC1CON = 0x0006; //set OC1 to PWM Mode
 
 OC1R =  512;   //50% dutycycle
 OC1RS = 1024;
 
 T2CON = 0x8000; //configure TMR2 (1:1)
 
 LEDPIN1 = OUTPUT;
 LEDPIN2 = OUTPUT;
 LEDPIN3 = OUTPUT;
 LEDPIN4 = OUTPUT;
 LEDPIN5 = OUTPUT;
 LEDPIN6 = OUTPUT;
 LEDPIN7 = OUTPUT;
 LEDPIN8 = OUTPUT;
    
 LCD_Initialize(); 
 CG_Build(); // Build custom character set
 
 if( SetDCOC1PWM(512) == -1){
     LCD_PutString("ERROR", 5); //if setting duty cycle fails...
     while(1){}   
 }

    while(1)
  {      
        play(AnotherO);
        
        //PR2 = 9090; //set register of timer to clock/freq
        
      
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