/*""FILE COMMENT""*******************************************************
* System Name	: CAC API for RX210xx
* File Name		: r_pdl_cac_RX210xx.h
* Version		: 0.20
* Contents		: CAC header
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

#ifndef R_PDL_CAC_RX210xx_H
#define R_PDL_CAC_RX210xx_H

/* Callback function storage */
extern VoidCallBackFunc rpdl_CAC_callback_func_freq_error;
extern VoidCallBackFunc rpdl_CAC_callback_func_measurement;
extern VoidCallBackFunc rpdl_CAC_callback_func_overflow;

/* Library prototypes */
bool R_CAC_CreateAll(
	const uint32_t,
	const uint8_t,
	const double,
	const uint16_t,
	const uint16_t,
	VoidCallBackFunc const,
	const uint8_t,
	VoidCallBackFunc const,
	const uint8_t,
	VoidCallBackFunc const,
	const uint8_t
);

bool R_CAC_DestroyAll(
	void
);

bool R_CAC_ControlAll(
	const uint8_t,
	const uint32_t,
	const uint16_t,
	const uint16_t
);

bool R_CAC_GetStatusAll(
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);

bool ReturnFalse(void);

/* Macro definitions */

#define R_CAC_Create(a, b, c, d, e, f, g, h, i, j, k) \
( \
( ( ((g) <= IPL_MAX) && ((i) <= IPL_MAX) && ((k) <= IPL_MAX) ) ) ? \
R_CAC_CreateAll( (a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k) ) : \
ReturnFalse() \
)

#define R_CAC_Destroy() \
( \
R_CAC_DestroyAll() \
)

#define R_CAC_Control(a, b, c, d) \
R_CAC_ControlAll( (a), (b), (c), (d) )

#define R_CAC_GetStatus(a, b, c, d) \
R_CAC_GetStatusAll( (a), (b), (c), (d) )

#endif
/* End of file */
