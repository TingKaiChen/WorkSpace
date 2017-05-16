/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210xx
* File Name		: Interrupt_CPB.c
* Version		: 0.20
* Contents		: Interrupt handlers for the CMT channels
* Customer		: 
* Model		 	:
* Order		 	:
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

#include "r_pdl_cpb.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_CPBn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for CPB channel n
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: CPB_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FILE COMMENT END""**************************************************/

#if FAST_INTC_VECTOR == VECT_COMPB_COMPB0
#pragma interrupt Interrupt_CPB0(vect=VECT_COMPB_COMPB0, fint)
#else
#pragma interrupt Interrupt_CPB0(vect=VECT_COMPB_COMPB0)
#endif
void Interrupt_CPB0(void)
{
	/* Call the user function */
	if (rpdl_CPB_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_CPB_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_COMPB_COMPB1
#pragma interrupt Interrupt_CPB1(vect=VECT_COMPB_COMPB1, fint)
#else
#pragma interrupt Interrupt_CPB1(vect=VECT_COMPB_COMPB1)
#endif
void Interrupt_CPB1(void)
{
	/* Call the user function */
	if (rpdl_CPB_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_CPB_callback_func[1]();
	}
}
/* End of file */
