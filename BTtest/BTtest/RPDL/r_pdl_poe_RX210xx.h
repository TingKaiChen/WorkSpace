/*""FILE COMMENT""*******************************************************
* System Name	: POE API for RX210xx
* File Name		: r_pdl_poe_RX210xx.h
* Version		: 0.20
* Contents		: POE API header
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

#ifndef R_PDL_POE_RX210xx_H
#define R_PDL_POE_RX210xx_H

#define POE_INTERRUPTS	2

/* Callback function storage */
extern VoidCallBackFunc rpdl_POE_callback_func[];

/* Library prototypes */
bool R_POE_SetAll(
	const uint32_t,
	const uint16_t,
	const uint16_t
);
bool R_POE_CreateAll(
	const uint8_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_POE_ControlAll(
	const uint8_t,
	const uint16_t,
	const uint8_t
);
bool R_POE_GetStatusAll(
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_POE_Set(a, b, c) \
( \
R_POE_SetAll( (a), (b), (c) ) \
)

#define R_POE_Create(a, b, c, d) \
( \
( ((d) <= IPL_MAX) ) ? \
R_POE_CreateAll( (a), (b), (c), (d)) : \
ReturnFalse() \
)

#define R_POE_Control(a, b, c) \
( \
R_POE_ControlAll( (a), (b), (c) ) \
)

#define R_POE_GetStatus(a) \
( \
R_POE_GetStatusAll( (a) ) \
)

#endif
/* End of file */
