/*
 * File:   main.c
 * Author: Panki
 *
 * Created on 19. Oktober 2016, 13:41
 */

//Selfdefined
#define FOSC 10000000
#define FCY (FOSC/2)
#include <libpic30.h>
#include "lcd.h"
//#include "lcd.c"

#include "xc.h"
#include "header.h"

#include <p24fj128ga010.h>

#define BAR0  0x00
#define BAR1  0x01
#define BAR2  0x02
#define BAR3  0x03
#define BAR4  0x04



int main(void) { 
      
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
 //LCD_PutChar(0x01);
 //LCD_PutChar(0x01);
 //LCD_PutString("HALLO GITTLI", 12);
 


 

 
 
    while(1)
  {
        LED1 = ON;
        LCD_PutChar(BAR0);
        __delay_ms(350);
        LED2 = ON;
        LCD_PutChar(BAR1);
        __delay_ms(350);
        LED3 = ON;
        LCD_PutChar(BAR2);
        __delay_ms(350);
        LED4 = ON;

        __delay_ms(350);
        LED5 = ON;
        LCD_PutChar(BAR3);
        __delay_ms(350);
        LED6 = ON;
        __delay_ms(350);
        LED7 = ON;
         LCD_PutChar(BAR4);
        __delay_ms(350);
        LED8 = ON;
        __delay_ms(350);
        LED1 = OFF;
        LED2 = OFF;
        LED3 = OFF;
        LED4 = OFF;
        LED5 = OFF;
        LED6 = OFF;
        LED7 = OFF;
        LED8 = OFF;
        LCD_ClearScreen();
        __delay_ms(350);
    }
  return 0;
}



