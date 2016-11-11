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

#include "lib/rtttl.h"

#include <p24fj128ga010.h>

#define CG0  0x00
#define CG1  0x01
#define CG2  0x02
#define CG3  0x03
#define CG4  0x04
#define CG5  0x05
#define CG6  0x06
#define CG7  0x07

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

char Sandstorm[]={"Sandstor:d=5,o=4,b=112:16e6,16e6,16e6,16e6,8e6,16e6,16e6,16a6,16a6,16a6,16a6,16g6,16g6,16g6,16d6,16e6,16e6,16e6,16e6,8e6,16e6,16a6,16e6,16e6,16e6,16e6,8e6,16e6,16d6,16e6"};
char Sandstorm2[]={"Sandstor:d=4,o=5,b=125:16e,16e,16e,16e,8e,16e,16e,16e,16e,16e,16e,8e,16a,16a,16a,16a,16a,16a,8a,16g,16g,16g,16g,16g,16g,8g,16d,16d,16e,16e,16e,16e,8e,16e,16e,16e,16e,16e,16e,8e,16a,16a,16e,16e,16e,16e,8e,16e,16e,16e,16e,16e,16e,8e"};
char Blue[]={"Blue:d=4,o=5,b=100:8a#6,8c#7,16a#6,16c#7,16d#7,16d#7,16d#6,8c#7,16c#7,16e#7,8f#7,16e#7,8d#7,16a#6,16c#7,16d#7,16d#7,16d#6,8c#7"};
char Toxicity[]={"Toxicity:d=4,o=5,b=125:g,8p,16g,16g,8d#.,16c,g,8p,16g,16g,8d#.,16c,8g,2d#,8c,8g,2d,8p,g,8p,8g,8g,8g,8g,8g,8g,8g,8a#,8g,8d#,d#,8f,8d#,8d#,16d,16d#,16d,16c,2d,2d#.,2d#,16g#,16g#,16g#,8g#,g#,8a#,8g#,8g#,2d,8p,8c,8g,2d#,8c,8g,2d#,8c,g#,a#,8g#,8g"};
char Riddle[]={"GigiDago:d=8,o=5,b=140:c,e,4f,f,g,f,e,d,c,4c,d,e,4e,d,e,4f,4g,f,e,d,c,4d,d,c,4c,c,e,4f,f,g,f,e,d,c,4c,d,e,4e,d,e,4f,4g,f,e,d,c,4d,d,c,4c"};
char IWasMade[]={"IWasMade:d=4,o=6,b=125:c,d,8d_,16c5,16p,8f,8g,16c5,16p,8g,f,d_,d,c,d,8d_,16f5,16p,8f,8g,16f5,16p,8g,f.,16f5,16p,16f5,16p,16f5,16p,c,d,8d_,16c5,16p,8f,8g,16c5,16p,8g,f,d_,d,c,d,8d_,16f5,16p,8f,8g,16f5,16p,8g,f.,16f5,16p,16f5,16p,16f5,16p,c,d,8d_,16c5,16p,8f,8g,16c5,16p,8g,f,d_,d,c,d,8d_,16f5,16p,8f,8g,16f5,16p,8g,f.,16f5,16p,16f5,16p,16f5,16p,8c5"};
char Freestyler[]={"Freestyl:d=16,o=5,b=160:8g6,8e6,8b,8g6,8e6,8b,8g6,8e6,8b,8f#6,8e6,8b,8f#6,8e6,8b,8d6,8c6,8g,8d6,8c6,8g,8d6,8c6,8g,8e6,8d6,8a,8e6,8d6,8a,8e6,a"};
char BTMain[]={"BadTouch:d=16,o=5,b=50:c#.7,g#.7,g#.7,g#7,a.7,a7,g#.7,a.7,8g#.7,g#.7,g#.7,g#7,a.7,a7,g#.7,a.7,g#.7,b.7,g#.7,g#.7,g#7,a.7,a7,g#.7,a.7,g#.7,8e7,8e7,8e.7,e.7,f#.7"};
char KnightRider[]={"Theme:d=4,o=6,b=63:16e,32f,32e,8b,16e7,32f7,32e7,8b,16e,32f,32e,16b,16e7,d7,8p,p,16e,32f,32e,8b,16e7,32f7,32e7,8b,16e,32f,32e,16b,16e7,f7,p"};
char Batman[]={"Theme:d=4,o=6,b=200:8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,g_5,2g_5,p,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,g_5,2g_5,p,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,8f5,8f5,8e5,8e5,8d_5,8d_5,8e5,8e5,g_5,2g_5,p,f5"};

int main(void) {

OC1CON = 0x0006; //set OC1 to PWM Mode
 
OC1R=512;								// init first duty cycle
OC1RS=1024;	
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
 
 /*if( SetDCOC1PWM(512) == -1){
     LCD_PutString("ERROR", 5); //if setting duty cycle fails...
     while(1){}   
 }*/

    while(1)
  {     
        LATA = 0x00; 
        CG_Build();
        
        LCD_ClearScreen();
        LCD_PutString("FREESTYLER ", 11);
        LCD_PutChar(CG4);
        LCD_PutChar(CG5);
        LED1 = ON;
        play(Freestyler);
        
        LCD_ClearScreen();
        LCD_PutString("I WAS MADE FOR  ", 16);
        LCD_PutChar(CG2);
        LCD_PutChar(CG3);
        LCD_PutString("-ING YOU", 8);
        LED2 = ON;
        play(IWasMade);
        
        LCD_ClearScreen();
        LCD_PutString("SANDSTORM ", 10);
        LCD_PutChar(CG0);
        LCD_PutChar(CG1);
        LCD_PutString("    DUDUDUDUDUDU ", 17);
        LCD_PutChar(CG0);
        LCD_PutChar(CG1);
        
        
        //LCD_PutChar();
        LED3 = ON;
        play(Sandstorm);
        
        LED4 = ON;
        play(Sandstorm);
        
        LCD_ClearScreen();
        LCD_PutString("S.O.A.D. ", 9);
        LCD_PutChar(CG6);
        LCD_PutChar(CG7);
        LCD_PutChar(CG6);
        LCD_PutChar(CG7);
        LCD_PutString("   TOXICITY", 11);
        LED5 = ON;
        play(Toxicity);
        
        CG_Build2(); //set second charset
        
        LCD_ClearScreen();
        LCD_PutString("GIGI D'AGOSTINO ", 16);
        LCD_PutChar(CG0);
        LCD_PutChar(CG1);
        LCD_PutString(" THE RIDDLE ", 12);
        LCD_PutChar(CG0);
        LCD_PutChar(CG1);
        LED6 = ON;
        play(Riddle);
        
        LCD_ClearScreen();
        LCD_PutString("KNIGHT RIDER", 12);
        LED7 = ON;
        play(KnightRider);
        
        LCD_ClearScreen();
        LCD_PutString("BATMAN ", 7);
        LCD_PutChar(CG2);
        LCD_PutChar(CG3);
        LCD_PutString("     ", 5);
        LCD_PutChar(CG2);
        LCD_PutChar(CG3);
        LED8 = ON;
        play(Batman);

    }
  return 0;
}