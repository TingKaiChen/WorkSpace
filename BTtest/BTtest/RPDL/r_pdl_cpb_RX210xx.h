/*""FILE COMMENT""*******************************************************
* System Name	: CPB API for RX210xx
* File Name		: r_pdl_cpb_RX210xx.h
* Version		: 0.20
* Contents		: CPB API header
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

#ifndef R_PDL_CPB_RX210xx_H
#define R_PDL_CPB_RX210xx_H

#define CPB_CHANNELS	2

/* Callback function storage */
extern VoidCallBackFunc rpdl_CPB_callback_func[CPB_CHANNELS];

/* Library prototypes */
bool R_CPB_CreateAll(
	const uint8_t,
	const uint16_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_CPB_DestroyAll(
	const uint8_t
);
bool R_CPB_GetStatusAll(
	volatile uint8_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_CPB_Create(a, b, c, d) \
( \
( ( ((a) < CPB_CHANNELS ) && ((d) <= IPL_MAX) ) ) ? \
R_CPB_CreateAll( (a), (b), (c), (d) ) : \
ReturnFalse() \
)

#define R_CPB_Destroy(a) \
( \
( (a) < CPB_CHANNELS ) ? \
R_CPB_DestroyAll( (a) ) : \
ReturnFalse() \
)

#define R_CPB_GetStatus(a) R_CPB_GetStatusAll(a)

#endif
/* End of file */
