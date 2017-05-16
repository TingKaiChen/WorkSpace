/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210xx
* File Name		: Interrupt_ELC.c
* Version		: 0.20
* Contents		: Interrupt handlers for the ELC.
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

#include "r_pdl_elc.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : ELC interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_ELSR1xI(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for ELC interrupts
*				  ELSR18I and ELSR19I
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
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FILE COMMENT END""**************************************************/

#if FAST_INTC_VECTOR == VECT_ELC_ELSR18I
#pragma interrupt Interrupt_ELSR18I(vect=VECT_ELC_ELSR18I, fint)
#else
#pragma interrupt Interrupt_ELSR18I(vect=VECT_ELC_ELSR18I)
#endif
void Interrupt_ELSR18I(void)
{
	/* Call the user function */
	if(rpdl_ELC_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_ELC_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_ELC_ELSR19I
#pragma interrupt Interrupt_ELSR19I(vect=VECT_ELC_ELSR19I, fint)
#else
#pragma interrupt Interrupt_ELSR19I(vect=VECT_ELC_ELSR19I)
#endif
void Interrupt_ELSR19I(void)
{
	/* Call the user function */
	if(rpdl_ELC_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_ELC_callback_func[1]();
	}
}
/* End of file */
