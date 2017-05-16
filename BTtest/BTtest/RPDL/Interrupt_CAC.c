/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210xx
* File Name		: Interrupt_CAC.c
* Version		: 0.20
* Contents		: Interrupt handler for the CAC
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

#include "r_pdl_cac.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : CAC interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_CAC_frequency_error(void)
*-------------------------------------------------------------------
* Function		: Frequency error interrupt processing function
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_CAC_callback_func_freq_error
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_CAC_FERRF
#pragma interrupt Interrupt_CAC_frequency_error(vect=VECT_CAC_FERRF, fint)
#else
#pragma interrupt Interrupt_CAC_frequency_error(vect=VECT_CAC_FERRF)
#endif
void Interrupt_CAC_frequency_error(void)
{
	/* Call the user function */
	if (rpdl_CAC_callback_func_freq_error != PDL_NO_FUNC)
	{
		rpdl_CAC_callback_func_freq_error();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : CAC interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_CAC_frequency_error(void)
*-------------------------------------------------------------------
* Function		: Measurement complete interrupt processing function
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_CAC_callback_func_measurement
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_CAC_MENDF
#pragma interrupt Interrupt_CAC_measurement_complete(vect=VECT_CAC_MENDF, fint)
#else
#pragma interrupt Interrupt_CAC_measurement_complete(vect=VECT_CAC_MENDF)
#endif
void Interrupt_CAC_measurement_complete(void)
{
	/* Call the user function */
	if (rpdl_CAC_callback_func_measurement != PDL_NO_FUNC)
	{
		rpdl_CAC_callback_func_measurement();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : CAC interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_CAC_frequency_error(void)
*-------------------------------------------------------------------
* Function		: Overflow interrupt processing function
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_CAC_callback_func_overflow
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_CAC_OVFF
#pragma interrupt Interrupt_CAC_overflow(vect=VECT_CAC_OVFF, fint)
#else
#pragma interrupt Interrupt_CAC_overflow(vect=VECT_CAC_OVFF)
#endif
void Interrupt_CAC_overflow(void)
{
	/* Call the user function */
	if (rpdl_CAC_callback_func_overflow != PDL_NO_FUNC)
	{
		rpdl_CAC_callback_func_overflow();
	}
}
/* End of file */
