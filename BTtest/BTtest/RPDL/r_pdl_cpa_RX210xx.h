/*""FILE COMMENT""*******************************************************
* System Name	     : Comparator A API for RX210
* File Name		: r_pdl_cpa_RX210xx.h
* Version		: 0.20
* Contents		: Comparator A API header
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

#ifndef R_PDL_CPA_RX210xx_H
#define R_PDL_CPA_RX210xx_H

#define CPA_NUM	2

/* Callback function storage */
extern VoidCallBackFunc rpdl_CPA_callback_func[CPA_NUM];

/* Library prototypes */
bool R_CPA_CreateAll(
	const uint8_t,         
	const uint16_t,        
	VoidCallBackFunc const,
	const uint8_t          
);

/* Library prototypes */
bool R_CPA_ControlAll(
	const uint8_t,         
	const uint8_t        
);

/* Library prototypes */
bool R_CPA_GetStatusAll(
	volatile uint8_t * const
);

bool ReturnFalse(void);

/* Macro definitions */

#define R_CPA_Create(a, b, c, d) \
( \
( ( ((a) < CPA_NUM ) && ((d) <= IPL_MAX) ) ) ? \
R_CPA_CreateAll( (a), (b), (c), (d)) : \
ReturnFalse() \
)

#define R_CPA_Control(a, b) \
( \
( (a) < CPA_NUM ) ? \
R_CPA_ControlAll( (a), (b) ) : \
ReturnFalse() \
)

#define R_CPA_GetStatus(a) \
( \
R_CPA_GetStatusAll( (a) ) \
)

#endif
/* End of file */
