/*""FILE COMMENT""*******************************************************
* System Name	: CGC API
* File Name		: r_pdl_cgc.h
* Version		: 0.20
* Contents		: CGC header
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

#ifndef R_PDL_CGC_H
#define R_PDL_CGC_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_CGC_Set(
	uint8_t,
	uint32_t,
	double,
	double,
	double,
	double,
	double,
	double
);

bool R_CGC_Control(
	uint8_t,
	uint32_t,
	uint8_t
);

bool R_CGC_GetStatus(
	uint16_t *
);

/* Clock source selection */
#define PDL_CGC_CLK_LOCO				0x01u
#define PDL_CGC_CLK_HOCO				0x02u
#define PDL_CGC_CLK_MAIN				0x04u
#define PDL_CGC_CLK_SUB_CLOCK			0x08u
#define PDL_CGC_CLK_PLL					0x10u
#define PDL_CGC_CLK_IWDTLOCO			0x20u

/* BCLK pin control */
#define PDL_CGC_BCLK_DIV_1				0x00000001ul
#define PDL_CGC_BCLK_DIV_2				0x00000002ul
#define PDL_CGC_BCLK_DISABLE			0x00000004ul
#define PDL_CGC_BCLK_ENABLE				0x00000008ul

/* Low-speed on-chip oscillator control */
#define PDL_CGC_LOCO_ENABLE				0x00000010ul
#define PDL_CGC_LOCO_DISABLE			0x00000020ul

/* High-speed on-chip oscillator control */
#define PDL_CGC_HOCO_ENABLE				0x00000040ul
#define PDL_CGC_HOCO_DISABLE			0x00000080ul

/* High-speed on-chip oscillator frequency control */
#define PDL_CGC_HOCO_32000				0x00000100ul
#define PDL_CGC_HOCO_36864				0x00000200ul
#define PDL_CGC_HOCO_40000				0x00000400ul
#define PDL_CGC_HOCO_50000				0x00000800ul

/* High-speed on-chip oscillator power control */
#define PDL_CGC_HOCO_POWER_ON			0x00001000ul
#define PDL_CGC_HOCO_POWER_OFF			0x00002000ul

/* Main clock oscillator control */
#define PDL_CGC_MAIN_ENABLE				0x00004000ul
#define PDL_CGC_MAIN_DISABLE			0x00008000ul

/* Main clock oscillator type */
#define PDL_CGC_MAIN_RESONATOR			0x00010000ul
#define PDL_CGC_MAIN_EXTERNAL			0x00020000ul

/* Main clock oscillator forced oscillation control */
#define PDL_CGC_MAIN_FORCED_ENABLE		0x00040000ul
#define PDL_CGC_MAIN_FORCED_DISABLE		0x00080000ul

/* Main clock oscillator drive type 1 */
#define PDL_CGC_MAIN_CERAMIC_SMT_16_24	0x00100000ul
#define PDL_CGC_MAIN_CERAMIC_LEAD_16_24	0x00200000ul

/* Main clock oscillator drive type 2 */
#define PDL_CGC_MAIN_1_8				0x00400000ul
#define PDL_CGC_MAIN_8_16				0x00800000ul
#define PDL_CGC_MAIN_16_24				0x01000000ul

/* Oscillation Stop Detection control */
#define PDL_CGC_OSC_STOP_ENABLE			0x02000000ul
#define PDL_CGC_OSC_STOP_INTERRUPT		0x04000000ul
#define PDL_CGC_OSC_STOP_DISABLE		0x08000000ul
#define PDL_CGC_OSC_STOP_CLEAR_FLAG		0x10000000ul

/* Sub-clock oscillator drive ability */
#define PDL_CGC_SUB_CLOCK_CL_LOW		0x20000000ul
#define PDL_CGC_SUB_CLOCK_CL_STANDARD	0x40000000ul

/* Sub-clock oscillator control */
#define PDL_CGC_SUB_CLOCK_ENABLE		0x01u
#define PDL_CGC_SUB_CLOCK_DISABLE		0x02u

/* PLL control */
#define PDL_CGC_PLL_ENABLE				0x04u
#define PDL_CGC_PLL_DISABLE				0x08u

/* IWDT-dedicated low-speed on-chip oscillator control */
#define PDL_CGC_IWDTLOCO_ENABLE			0x10u
#define PDL_CGC_IWDTLOCO_DISABLE		0x20u

#endif
/* End of file */
