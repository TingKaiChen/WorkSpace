/*""FILE COMMENT""*******************************************************
* System Name	: DAC API for RX210xx
* File Name		: r_pdl_dac_10_RX210xx.h
* Version		: 0.20
* Contents		: DAC header
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

#ifndef R_PDL_DAC_RX210xx_H
#define R_PDL_DAC_RX210xx_H

/* Library prototypes */
bool R_DAC_10_CreateAll(
	const uint8_t,
	const uint16_t,
	const uint16_t
);
bool R_DAC_10_DestroyAll(
	const uint8_t
);
bool R_DAC_10_WriteAll(
	const uint8_t,
	const uint16_t,
	const uint16_t
);

/* Macro definitions */

#define R_DAC_10_Create(a, b, c) \
( \
R_DAC_10_CreateAll( (a), (b), (c) ) \
)

#define R_DAC_10_Destroy(a) \
( \
R_DAC_10_DestroyAll( (a) ) \
)

#define R_DAC_10_Write(a, b, c) \
( \
R_DAC_10_WriteAll( (a), (b), (c) ) \
)

#endif
/* End of file */
