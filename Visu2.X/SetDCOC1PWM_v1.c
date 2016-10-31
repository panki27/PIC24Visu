 
#include <outcompare.h>

#if defined (ocmp_v1_1) ||defined (ocmp_v1_2) || defined (LIB_BUILD)
/*************************************************************************************
Function Prototype : char SetDCOC1PWM_v1(unsigned int dutycycle)

Include            : outcompare.h
 
Description        : For seamless migration, it is recommended to call the above function as "SetDCOC1PWM".
                     This function configures the Output Compare Secondary Duty Cycle register (OCxRS) 
					 when the module is in PWM mode.

Arguments          : dutycycle - This is the duty cycle value to be stored into Output
                     Compare Secondary Duty Cycle register (OCxRS).
 
Return Value       : Returns '1' on successful loading value else return '-1'.
 
Remarks            : The Output Compare Secondary Duty Cycle register (OCxRS) will be
                     configured with new value only if the module is in PWM mode.
**************************************************************************************/

char SetDCOC1PWM_v1(unsigned int dutycycle)
{   
    /* check if OC is in PWM Mode */
    if((OC1CONbits.OCM & 0x06) == 0x06) 
    {
       OC1RS = dutycycle;   /* assign to OCRS */
       return 1;
    }
    else
       return -1;    
}

#else
#warning "Does not build on this target"
#endif
