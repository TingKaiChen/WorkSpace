/*""FILE COMMENT""*******************************************************
* System Name	: RTC Interrupt program for RX210xx
* File Name 	: Interrupt_RTC.c
* Version		: 0.20
* Contents		: Interrupt handler for RTC
* Customer		: 
* Model			: 
* Order			: 
* CPU			: RX
* Compiler		: RXC
* OS			: Nothing
* Programmer	: 
* Note			: 
************************************************************************
* Copyright, 2011. Renesas Electronics Corporation
* and Renesas Solutions Corporation
************************************************************************
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FILE COMMENT END""**************************************************/

#include "r_pdl_rtc.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline: RTC periodic interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_RTC_PRD(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for RTC
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_RTC_Periodic_callback_func()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/
#if FAST_INTC_VECTOR == VECT_RTC_PRD
#pragma interrupt Interrupt_RTC_PRD(vect=VECT_RTC_PRD, fint)
#else
#pragma interrupt Interrupt_RTC_PRD(vect=VECT_RTC_PRD)
#endif
void Interrupt_RTC_PRD(void)
{
	/* Call the user function */
	if (rpdl_RTC_Periodic_callback_func != PDL_NO_FUNC)
	{
		rpdl_RTC_Periodic_callback_func();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: RTC alarm interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_RTC_ALM(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for RTC
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_RTC_Alarm_callback_func()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/
#if FAST_INTC_VECTOR == VECT_RTC_ALM
#pragma interrupt Interrupt_RTC_ALM(vect=VECT_RTC_ALM, fint)
#else
#pragma interrupt Interrupt_RTC_ALM(vect=VECT_RTC_ALM)
#endif
void Interrupt_RTC_ALM(void)
{
	/* Call the user function */
	if (rpdl_RTC_Alarm_callback_func != PDL_NO_FUNC)
	{
		rpdl_RTC_Alarm_callback_func();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: RTC Carry interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_RTC_CUP(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for RTC
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: 
*-------------------------------------------------------------------
* Notes			: This interrupt is not used.
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/
#if FAST_INTC_VECTOR == VECT_RTC_COUNTUP
#pragma interrupt Interrupt_RTC_CUP(vect=VECT_RTC_COUNTUP, fint)
#else
#pragma interrupt Interrupt_RTC_CUP(vect=VECT_RTC_COUNTUP)
#endif
void Interrupt_RTC_CUP(void)
{
	/* Disable further requests */
	ICU.IER[IER_RTC_COUNTUP].BIT.IEN_RTC_COUNTUP = 0;
}

/* End of file */
