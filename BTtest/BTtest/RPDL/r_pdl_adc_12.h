/*""FILE COMMENT""*******************************************************
* System Name	: 12-bit ADC API for RX210xx
* File Name		: r_pdl_adc_12.h
* Version		: 0.20
* Contents		: ADC_12 function prototypes
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

#ifndef R_PDL_ADC_12_H
#define R_PDL_ADC_12_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */

bool R_ADC_12_Set(
	uint32_t
);

bool R_ADC_12_CreateChannel(
	uint8_t,
	uint8_t,
	uint16_t,
	double
);

bool R_ADC_12_CreateUnit(
	uint8_t,
	uint32_t,
	uint32_t,
	uint32_t,
	double,
	double,
	double,
	void *,
	uint8_t,
	void *,
	uint8_t
);

bool R_ADC_12_Control(
	uint8_t
);

bool R_ADC_12_Read(
	uint8_t,
	uint16_t *,
	uint16_t *
);

bool R_ADC_12_Destroy(
	uint8_t
);


/* Options of configuration for R_ADC_12_SetAll() */


#define PDL_ADC_12_PIN_AN000_P40				0x00000001ul
#define PDL_ADC_12_PIN_AN001_P41				0x00000002ul
#define PDL_ADC_12_PIN_AN002_P42				0x00000004ul
#define PDL_ADC_12_PIN_AN003_P43				0x00000008ul
#define PDL_ADC_12_PIN_AN004_P44				0x00000010ul
#define PDL_ADC_12_PIN_AN005_P45				0x00000020ul
#define PDL_ADC_12_PIN_AN006_P46				0x00000040ul
#define PDL_ADC_12_PIN_AN007_P47				0x00000080ul
#define PDL_ADC_12_PIN_AN008_PE0				0x00000100ul
#define PDL_ADC_12_PIN_AN009_PE1				0x00000200ul
#define PDL_ADC_12_PIN_AN010_PE2				0x00000400ul
#define PDL_ADC_12_PIN_AN011_PE3				0x00000800ul
#define PDL_ADC_12_PIN_AN012_PE4				0x00001000ul
#define PDL_ADC_12_PIN_AN013_PE5				0x00002000ul
#define PDL_ADC_12_PIN_AN014_PE6				0x00004000ul
#define PDL_ADC_12_PIN_AN015_PE7				0x00008000ul
#define PDL_ADC_12_PIN_ADTRG0_P07				0x00010000ul
#define PDL_ADC_12_PIN_ADTRG0_P16				0x00020000ul
#define PDL_ADC_12_PIN_ADTRG0_P25				0x00040000ul


/* Options of configuration for R_ADC_12_CreateUnitAll() */


/* ADEXICR: Input source */
#define PDL_ADC_12_INPUT_AN						0x00000001ul
#define PDL_ADC_12_INPUT_TMPSR					0x00000002ul
#define PDL_ADC_12_INPUT_REF					0x00000004ul

#define PDL_ADC_12_INPUT_TS						(PDL_ADC_12_INPUT_TMPSR | \
												PDL_ADC_12_SYNC_TRIGGER_ENABLE | \
												PDL_ADC_12_VALUE_ADDITION_0)

/* ADCSR: Scan mode */
#define PDL_ADC_12_MODE_SINGLE_CYCLE 			0x00000008ul
#define PDL_ADC_12_MODE_CONTINUOUS				0x00000010ul
#define PDL_ADC_12_MODE_GROUP					0x00000020ul

#define PDL_ADC_12_SCAN_SINGLE 					(PDL_ADC_12_MODE_SINGLE_CYCLE)
#define PDL_ADC_12_SCAN_CONTINUOUS				(PDL_ADC_12_MODE_CONTINUOUS | \
												PDL_ADC_12_INPUT_AN)
#define PDL_ADC_12_SCAN_GROUP					(PDL_ADC_12_MODE_GROUP | \
												PDL_ADC_12_INPUT_AN | \
												PDL_ADC_12_SYNC_TRIGGER_ENABLE)

/* ADCSR: Trigger source enabling*/
#define PDL_ADC_12_ASYNC_TRIGGER_ENABLE			0x00000040ul
#define PDL_ADC_12_SYNC_TRIGGER_ENABLE			0x00000080ul

/* ADADC: Value addition */
#define PDL_ADC_12_VALUE_ADDITION_0				0x00000100ul
#define PDL_ADC_12_VALUE_ADDITION_1				0x00000200ul
#define PDL_ADC_12_VALUE_ADDITION_2				0x00000400ul
#define PDL_ADC_12_VALUE_ADDITION_3				0x00000800ul

/* ADCER: Data alignment */
#define PDL_ADC_12_DATA_ALIGNMENT_RIGHT			0x00001000ul
#define PDL_ADC_12_DATA_ALIGNMENT_LEFT			0x00002000ul

/* ADCER : Self-diagnostic */
#define PDL_ADC_12_DIAG_DISABLE					0x00004000ul
#define PDL_ADC_12_DIAG_VREFH0_ROTATED			0x00008000ul
#define PDL_ADC_12_DIAG_VREFH0_ZERO				0x00010000ul
#define PDL_ADC_12_DIAG_VREFH0_HALF				0x00020000ul
#define PDL_ADC_12_DIAG_VREFH0_FULL				0x00040000ul

#define PDL_ADC_12_SELF_DIAGNOSTIC_DISABLE			(PDL_ADC_12_DIAG_DISABLE)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_ROTATED	(PDL_ADC_12_DIAG_VREFH0_ROTATED | \
													PDL_ADC_12_INPUT_AN)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_ZERO		(PDL_ADC_12_DIAG_VREFH0_ZERO | \
													PDL_ADC_12_INPUT_AN)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_HALF		(PDL_ADC_12_DIAG_VREFH0_HALF | \
													PDL_ADC_12_INPUT_AN)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_FULL		(PDL_ADC_12_DIAG_VREFH0_FULL | \
													PDL_ADC_12_INPUT_AN)

/* ADCER: Result register clearing */
#define PDL_ADC_12_RETAIN_RESULT				0x00080000ul
#define PDL_ADC_12_CLEAR_RESULT					0x00100000ul

/* ADDISCR: Disconnection detection */
#define PDL_ADC_12_DDA_DISABLE					0x00200000ul
#define PDL_ADC_12_DDA_PRECHARGE				0x00400000ul
#define PDL_ADC_12_DDA_DISCHARGE				0x00800000ul

#define PDL_ADC_12_ADDISCR_CALCULATE			0x01000000ul
#define PDL_ADC_12_ADDISCR_SPECIFY				0x02000000ul

/* ADSHCR: Sample-and-hold */
#define PDL_ADC_12_ADSHCR_CALCULATE				0x04000000ul
#define PDL_ADC_12_ADSHCR_SPECIFY				0x08000000ul

/*  ADSSTR: Sampling time calcuation control */
#define PDL_ADC_12_ADSSTR_CALCULATE				0x10000000ul
#define PDL_ADC_12_ADSSTR_SPECIFY				0x20000000ul


/* Options of group_configuration for R_ADC_12_CreateUnitAll() */


/* Sync trigger source selection for Group A & B */
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG0AN		0x0001u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG0BN		0x0002u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRGAN			0x0004u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG0EN  		0x0008u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG0FN 		0x0010u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG4AN  		0x0020u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG4BN  		0x0040u
#define PDL_ADC_12_GP_TRIGGER_MTU_TRG4ABN  		0x0080u
#define PDL_ADC_12_GP_TRIGGER_ELC				0x0100u

/* DTC trigger control */
#define PDL_ADC_12_GP_DMAC_DTC_TRIGGER_DISABLE	0x0200u
#define PDL_ADC_12_GP_DMAC_TRIGGER_ENABLE		0x0400u
#define PDL_ADC_12_GP_DTC_TRIGGER_ENABLE		0x0800u


/* Options of configuration for R_ADC_12_CreateChannelAll() */


/* ADANSA, ADANSB: Group selection */
#define PDL_ADC_12_CH_GROUP_A					0x0001u
#define PDL_ADC_12_CH_GROUP_B					0x0002u

/* ADADS: Value addition */
#define PDL_ADC_12_CH_VALUE_ADDITION_DISABLE	0x0008u
#define PDL_ADC_12_CH_VALUE_ADDITION_ENABLE		0x0010u

/* ADSSTR: Sampling time calcuation control */
#define PDL_ADC_12_CH_ADSSTR_CALCULATE			0x0020u
#define PDL_ADC_12_CH_ADSSTR_SPECIFY			0x0040u

/* ADSHCR: Dedicated sample-and-hold circuit control */
#define PDL_ADC_12_CH_SAMPLE_AND_HOLD_DISABLE	0x0080u
#define PDL_ADC_12_CH_SAMPLE_AND_HOLD_ENABLE	0x0100u

/* ADCSR: Double trigger control */
#define PDL_ADC_12_CH_DOUBLE_TRIGGER_DISABLE	0x0200u
#define PDL_ADC_12_CH_DOUBLE_TRIGGER_ENABLE		0x0400u


/* Options of ADC_control for R_ADC_12_ControlAll() */


/* On / off control */
#define PDL_ADC_12_0_ON							0x01u
#define PDL_ADC_12_0_OFF						0x02u

/* CPU control */
#define PDL_ADC_12_CPU_ON						0x10u
#define PDL_ADC_12_CPU_OFF						0x20u

#endif
/* End of file */
