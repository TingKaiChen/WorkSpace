/*""FILE COMMENT""*******************************************************
* System Name	: CPA API for RX210xx
* File Name		: r_pdl_cpa.h
* Version		: 0.20
* Contents		: CPA API header
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

#ifndef R_PDL_CPA_H
#define R_PDL_CPA_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_CPA_Create(
	uint8_t,
	uint16_t,
	void *,
	uint8_t
);
bool R_CPA_Control(
	uint8_t,
	uint8_t
);
bool R_CPA_GetStatus(
	uint8_t *
);

 /* Interrupt/Reset Enable option */
#define PDL_CPA_INTERRUPT_RESET_DISABLE     0x0001u  
#define PDL_CPA_INTERRUPT_RESET_ENABLE      0x0002u  

/* Digital Filter option */
#define PDL_CPA_FILTER_DISABLE              0x0004u
#define PDL_CPA_FILTER_LOCO_DIV_1           0x0008u
#define PDL_CPA_FILTER_LOCO_DIV_2           0x0010u
#define PDL_CPA_FILTER_LOCO_DIV_4           0x0020u
#define PDL_CPA_FILTER_LOCO_DIV_8           0x0040u

/* Mode Selection */
#define PDL_CPA_MODE_SELECT_INTERRUPT       0x0080u
#define PDL_CPA_MODE_SELECT_RESET           0x0100u
                                       
/* Negation Selection */               
#define PDL_CPA_NEGATION_AFTER_DETECT       0x0200u 
#define PDL_CPA_NEGATION_AFTER_RESET        0x0400u

/* Interrupt/Event Generation Condition Selection */
#define PDL_CPA_IRQ_ABOVE_N_EQUAL_CVREFA    0x0800u
#define PDL_CPA_IRQ_BELOW_CVREFA            0x1000u
#define PDL_CPA_IRQ_CROSS_CVREFA            0x2000u

/* Interrupt Type Selection */
#define PDL_CPA_MASKABLE_INTERRUPT          0x4000u
#define PDL_CPA_NONMASKABLE_INTERRUPT       0x8000u

/* Comparator circuit enable option */
#define PDL_CPA_LVD_CIRCUIT_DISABLE	        0x01u
#define PDL_CPA_LVD_CIRCUIT_ENABLE	 	    0x02u
                                            	                                                                                                       
#endif                                          
/* End of file */
                 
