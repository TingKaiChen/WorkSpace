/*""FILE COMMENT""*******************************************************
* System Name	: Low Voltage detection circuit (LVD) API for RX210xx
* File Name		: r_pdl_lvd_RX210xx.h
* Version		: 0.20
* Contents		: LVD API header
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

#ifndef R_PDL_LVD_RX210xx_H
#define R_PDL_LVD_RX210xx_H

extern VoidCallBackFunc rpdl_LVC_VDET1_callback_func;
extern VoidCallBackFunc rpdl_LVC_VDET2_callback_func;

/* Library prototypes */
bool R_LVD_CreateAll(const uint32_t,
					 const uint32_t,
					 const uint16_t,
					 const uint16_t,
					 VoidCallBackFunc const,
					 const uint8_t,
					 VoidCallBackFunc const,
					 const uint8_t
);
					 
bool R_LVD_ControlAll(
	const uint32_t,
	const uint16_t
);

bool R_LVD_GetStatusAll(
	volatile uint8_t * const
);

/* Macro definitions */
/*Call R_LVD_CreateAll if interrupt priorities are within max limit.*/
#define R_LVD_Create(a, b, c, d, e, f, g, h) \
( \
( ((f) <= IPL_MAX) &&  ((h) <= IPL_MAX)) ? \
R_LVD_CreateAll((a), (b), (c), (d), (e), (f), (g), (h))  : \
ReturnFalse() \
)

#define R_LVD_Control(a, b) \
( \
R_LVD_ControlAll( (a), (b) ) \
)

#define R_LVD_GetStatus(a) \
( \
R_LVD_GetStatusAll( (a) ) \
)

#endif
/* End of file */
