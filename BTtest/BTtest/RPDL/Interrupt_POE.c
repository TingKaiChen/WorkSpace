/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210
* File Name		: Interrupt_POE.c
* Version		: 0.20
* Contents		: Interrupt handlers for the Port Output Enable module
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

#include "r_pdl_poe.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : POE interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_OEIn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for POE interrupt n
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: POE_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_POE_OEI1
#pragma interrupt Interrupt_OEI1(vect=VECT_POE_OEI1, fint)
#else
#pragma interrupt Interrupt_OEI1(vect=VECT_POE_OEI1)
#endif
void Interrupt_OEI1(void)
{
	/* Call the user function */
	if (rpdl_POE_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_POE_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_POE_OEI2
#pragma interrupt Interrupt_OEI2(vect=VECT_POE_OEI2, fint)
#else
#pragma interrupt Interrupt_OEI2(vect=VECT_POE_OEI2)
#endif
void Interrupt_OEI2(void)
{
	/* Call the user function */
	if (rpdl_POE_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_POE_callback_func[1]();
	}
}


/* End of file */
