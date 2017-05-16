/*""FILE COMMENT""*******************************************************
* System Name	: BSC API for RX210
* File Name		: r_pdl_bsc_RX210xx.h
* Version		: 0.20
* Contents		: BSC API header
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

#ifndef R_PDL_BSC_RX210xx_H
#define R_PDL_BSC_RX210xx_H

#define BSC_AREAS	4

/* Callback function storage */
extern VoidCallBackFunc rpdl_BSC_callback_func;

/* Library prototypes */
bool R_BSC_SetAll(
	const uint16_t
);
bool R_BSC_CreateAll(
	const uint16_t,
	const uint32_t,
	const uint16_t,
	const uint8_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_BSC_CreateAreaAll(
	const uint8_t,
	const uint16_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t,
	const uint8_t
);
bool R_BSC_DestroyAll(
	const uint8_t
);
bool R_BSC_ControlAll(
	const uint8_t
);
bool R_BSC_GetStatusAll(
	volatile uint8_t * const,
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_BSC_Set(a) \
( \
R_BSC_SetAll( (a) ) \
)

#define R_BSC_Create(a, b, c, d, e, f) \
( \
( (f) <= IPL_MAX ) ? \
R_BSC_CreateAll( (a), (b), (c), (d), (e), (f) ) : \
ReturnFalse() \
)

#define R_BSC_CreateArea(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) \
( \
( (a) < BSC_AREAS ) ? \
R_BSC_CreateAreaAll( (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k), (l), (m), (n), (o), (p) ) : \
ReturnFalse() \
)

#define R_BSC_Destroy(a) \
( \
( (a) < BSC_AREAS ) ? \
R_BSC_DestroyAll( (a) ) : \
ReturnFalse() \
)

#define R_BSC_Control(a) \
( \
R_BSC_ControlAll( (a) ) \
)

#define R_BSC_GetStatus(a, b) \
( \
R_BSC_GetStatusAll( (a), (b) ) \
)

#endif
/* End of file */
