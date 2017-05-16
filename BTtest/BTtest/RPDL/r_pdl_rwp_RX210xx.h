/*""FILE COMMENT""*******************************************************
* System Name	: Register Write Protection (RWP) API for RX210xx
* File Name		: r_pdl_rwp_RX210xx.h
* Version		: 0.20
* Contents		: RWP header
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

#ifndef R_PDL_RWP_RX200xx_H
#define R_PDL_RWP_RX200xx_H

/* Library prototypes */

bool R_RWP_ControlAll(
	const uint8_t
);
bool R_RWP_GetStatusAll(
	volatile uint8_t * const,
	volatile uint8_t * const
);

/* Macro definitions */

#define R_RWP_Control(a) \
( \
R_RWP_ControlAll( (a) ) \
)

#define R_RWP_GetStatus(a, b) \
( \
R_RWP_GetStatusAll( (a), (b) ) \
)

#endif
/* End of file */
