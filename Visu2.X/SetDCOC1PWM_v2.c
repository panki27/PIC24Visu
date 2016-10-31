 
#include <outcompare.h>

#if defined (ocmp_v2_1) || defined (ocmp_v2_2) || defined (ocmp_v2_3)|| defined (ocmp_v2_4) || defined (ocmp_v2_5)|| defined (LIB_BUILD)
/*************************************************************************************
Function Prototype : char SetDCOC1PWM_GB(unsigned int dutycycle,unsigned int period)

Include            : outcompare.h
 
Description        : For seamless migration, it is recommended to call the above function as "SetDCOC1PWM".
                     This function configures the Output Compare Secondary Duty Cycle register (OCxRS) 
					 when the module is in PWM mode.

Arguments          : dutycycle - This is the duty cycle value to be stored into Output
                     Compare Main Duty Cycle register (OCxR).
                     period - This is the period stored into Secondary register (OCxRS)
 
Return Value       : Returns '1' on successful loading value else return '-1'.
 
Remarks            : The Output Compare Main and Secondary register will be
                     configured with new value only if the module is in PWM mode.
**************************************************************************************/

char SetDCOC1PWM_GB(unsigned int dutycycle,unsigned int period)
{   
    /* check if OC is in PWM Mode */
    if((OC1CON1bits.OCM & 0x06) == 0x06) 
    {
       OC1R = dutycycle;   /* assign to OCRS */
       OC1RS = period;
       return 1;
    }   
    else
       return -1;       
}

#else
#warning "Does not build on this target"
#endif
