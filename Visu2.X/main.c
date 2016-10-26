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
 //LCD_PutString("PANKI IS KING   DEUS VULT", 25);
 LCD_PutChar(0x00);
    while(1)
  {
        LED1 = ON;
        __delay_ms(350);
        LED2 = ON;
        __delay_ms(350);
        LED3 = ON;
        __delay_ms(350);
        LED4 = ON;
        __delay_ms(350);
        LED5 = ON;
        __delay_ms(350);
        LED6 = ON;
        __delay_ms(350);
        LED7 = ON;
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
        __delay_ms(350);
    }
  return 0;
}



