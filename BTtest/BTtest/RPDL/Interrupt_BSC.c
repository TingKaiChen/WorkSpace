/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210xx
* File Name		: Interrupt_BSC.c
* Version		: 0.20
* Contents		: Interrupt handler for the BSC
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

#include "r_pdl_bsc.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : BSC interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_BSC(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for the BSC
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_BSC_callback_func
*-------------------------------------------------------------------
* Notes		 	:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_BSC_BUSERR
#pragma interrupt Interrupt_BSC(vect=VECT_BSC_BUSERR, fint)
#else
#pragma interrupt Interrupt_BSC(vect=VECT_BSC_BUSERR)
#endif
void Interrupt_BSC(void)
{
#ifndef DEVICE_PACKAGE_100_PIN
	/* This peripheral is not available on the 80-pin or 64-pin packages */
	nop();
#else
	/* Call the user function */
	if (rpdl_BSC_callback_func != PDL_NO_FUNC)
	{
		rpdl_BSC_callback_func();
	}
#endif
}
/* End of file */
