/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210xx
* File Name		: Interrupt_not_RPDL.c
* Version		: 0.20
* Contents		: Interrupt handlers for peripherals outside the scope
*				: of RPDL
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

#include "r_pdl_common_defs_RX210xx.h"
#include "r_pdl_user_definitions.h"

#if FAST_INTC_VECTOR == VECT_FCU_FIFERR
#pragma interrupt Interrupt_FIFERR(vect=VECT_FCU_FIFERR, fint)
#else
#pragma interrupt Interrupt_FIFERR(vect=VECT_FCU_FIFERR)
#endif
void Interrupt_FIFERR(void)
{
	/* The user can put their own code here */
	nop();
}

#if FAST_INTC_VECTOR == VECT_FCU_FRDYI
#pragma interrupt Interrupt_FRDYI(vect=VECT_FCU_FRDYI, fint)
#else
#pragma interrupt Interrupt_FRDYI(vect=VECT_FCU_FRDYI)
#endif
void Interrupt_FRDYI(void)
{
	/* The user can put their own code here */
	nop();
}
/* End of file */
