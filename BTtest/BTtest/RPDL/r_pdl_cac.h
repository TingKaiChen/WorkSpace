/*""FILE COMMENT""*******************************************************
* System Name	: CAC API
* File Name		: r_pdl_cac.h
* Version		: 0.20
* Contents		: CAC header
* Customer		:
* Model			:
* Order			:
* CPU			: RX
* Compiler		: RXC
* OS			:
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

#ifndef R_PDL_CAC_H
#define R_PDL_CAC_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_CAC_Create(
	uint32_t,
	uint8_t,
	double,
	uint16_t,
	uint16_t,
	void *,
	uint8_t,
	void *,
	uint8_t,
	void *,
	uint8_t
);

bool R_CAC_Destroy(
	void
);

bool R_CAC_Control(
	uint8_t,
	uint32_t,
	uint16_t,
	uint16_t
);

bool R_CAC_GetStatus(
	uint8_t *,
	uint16_t *,
	uint16_t *,
	uint16_t *
);

/* Reference signal selection */
#define PDL_CAC_REFERENCE_MAIN			0x00000001ul
#define PDL_CAC_REFERENCE_SUB_CLOCK		0x00000002ul
#define PDL_CAC_REFERENCE_HOCO			0x00000004ul
#define PDL_CAC_REFERENCE_LOCO			0x00000008ul
#define PDL_CAC_REFERENCE_IWDTLOCO		0x00000010ul
#define PDL_CAC_REFERENCE_CACREF		0x00000020ul

/* Reference signal edge selection */
#define PDL_CAC_REFERENCE_RISING		0x00000040ul
#define PDL_CAC_REFERENCE_FALLING		0x00000080ul
#define PDL_CAC_REFERENCE_BOTH			0x00000100ul

/* Reference signal division selection */
#define PDL_CAC_REFERENCE_DIV_32		0x00000200ul
#define PDL_CAC_REFERENCE_DIV_128		0x00000400ul
#define PDL_CAC_REFERENCE_DIV_1024		0x00000800ul
#define PDL_CAC_REFERENCE_DIV_8192		0x00001000ul

/* Measured clock selection  */
#define PDL_CAC_MEASURE_MAIN			0x00002000ul
#define PDL_CAC_MEASURE_SUB_CLOCK		0x00004000ul
#define PDL_CAC_MEASURE_HOCO			0x00008000ul
#define PDL_CAC_MEASURE_LOCO			0x00010000ul
#define PDL_CAC_MEASURE_IWDTLOCO		0x00020000ul

/* Measured clock division  */
#define PDL_CAC_MEASURE_DIV_1			0x00040000ul
#define PDL_CAC_MEASURE_DIV_4			0x00080000ul
#define PDL_CAC_MEASURE_DIV_8			0x00100000ul
#define PDL_CAC_MEASURE_DIV_32			0x00200000ul

/* Limit value calculation  */
#define PDL_CAC_LIMIT_TOLERANCE			0x00400000ul
#define PDL_CAC_LIMIT_REGISTER			0x00800000ul

/* External input pin selection  */
#define PDL_CAC_CACREF_PORT_A_0			0x01u
#define PDL_CAC_CACREF_PORT_C_7			0x02u
#define PDL_CAC_CACREF_PORT_H_0			0x04u

/* Digital filter selection  */
#define PDL_CAC_CACREF_FILTER_DISABLE	0x08u
#define PDL_CAC_CACREF_FILTER_DIV_1		0x10u
#define PDL_CAC_CACREF_FILTER_DIV_4		0x20u
#define PDL_CAC_CACREF_FILTER_DIV_16	0x40u

/* Flag clearing control */
#define PDL_CAC_CLEAR_FREQUENCY_ERROR	0x01u
#define PDL_CAC_CLEAR_MEASUREMENT		0x02u
#define PDL_CAC_CLEAR_OVERFLOW			0x04u

/* Operation control */
#define PDL_CAC_DISABLE					0x08u
#define PDL_CAC_ENABLE					0x10u

#endif
/* End of file */
