/*""FILE COMMENT""*******************************************************
* System Name	: I/O Port API
* File Name		: r_pdl_io_port.h
* Version		: 0.20
* Contents		: I/O Port API header
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

#ifndef R_PDL_IO_PORT_H
#define R_PDL_IO_PORT_H

#include "r_pdl_common_defs_RX210xx.h"

/* Function prototypes */
bool R_IO_PORT_Set(
	uint16_t,
	uint16_t
);
bool R_IO_PORT_ReadControl(
	uint16_t,
	uint8_t,
	uint16_t *
);
bool R_IO_PORT_ModifyControl(
	uint16_t,
	uint8_t,
	uint16_t
);
bool R_IO_PORT_Read(
	uint16_t,
	uint8_t *
);
bool R_IO_PORT_Write(
	uint16_t,
	uint8_t
);
bool R_IO_PORT_Compare(
	uint16_t,
	uint8_t,
	void *
);
bool R_IO_PORT_Modify(
	uint16_t,
	uint16_t,
	uint8_t
);
bool R_IO_PORT_Wait(
	uint16_t,
	uint8_t
);

/* I/O Ports*/
#define PDL_IO_PORT_0	0xF000u	/* Port 0 */
#define PDL_IO_PORT_1	0xF001u	/* Port 1 */
#define PDL_IO_PORT_2	0xF002u	/* Port 2 */
#define PDL_IO_PORT_3	0xF003u	/* Port 3 */
#define PDL_IO_PORT_4	0xF004u	/* Port 4 */
#define PDL_IO_PORT_5	0xF005u	/* Port 5 */
#define PDL_IO_PORT_A	0xF00Au	/* Port A */
#define PDL_IO_PORT_B	0xF00Bu	/* Port B */
#define PDL_IO_PORT_C	0xF00Cu	/* Port C */
#define PDL_IO_PORT_D	0xF00Du	/* Port D */
#define PDL_IO_PORT_E	0xF00Eu	/* Port E */
#define PDL_IO_PORT_H	0xF011u	/* Port H */
#define PDL_IO_PORT_J	0xF012u	/* Port J */

/* I/O port pins */
#define PDL_IO_PORT_0_3 0x0008u	/* P03 */
#define PDL_IO_PORT_0_5 0x0020u	/* P05 */
#define PDL_IO_PORT_0_7 0x0080u	/* P07 */

#define PDL_IO_PORT_1_2 0x0104u	/* P12 */
#define PDL_IO_PORT_1_3 0x0108u	/* P13 */
#define PDL_IO_PORT_1_4 0x0110u	/* P14 */
#define PDL_IO_PORT_1_5 0x0120u	/* P15 */
#define PDL_IO_PORT_1_6 0x0140u	/* P16 */
#define PDL_IO_PORT_1_7 0x0180u	/* P17 */

#define PDL_IO_PORT_2_0 0x0201u	/* P20 */
#define PDL_IO_PORT_2_1 0x0202u	/* P21 */
#define PDL_IO_PORT_2_2 0x0204u	/* P22 */
#define PDL_IO_PORT_2_3 0x0208u	/* P23 */
#define PDL_IO_PORT_2_4 0x0210u	/* P24 */
#define PDL_IO_PORT_2_5 0x0220u	/* P25 */
#define PDL_IO_PORT_2_6 0x0240u	/* P26 */
#define PDL_IO_PORT_2_7 0x0280u	/* P27 */

#define PDL_IO_PORT_3_0 0x0301u	/* P30 */
#define PDL_IO_PORT_3_1 0x0302u	/* P31 */
#define PDL_IO_PORT_3_2 0x0304u	/* P32 */
#define PDL_IO_PORT_3_3 0x0308u	/* P33 */
#define PDL_IO_PORT_3_4 0x0310u	/* P34 */
#define PDL_IO_PORT_3_5 0x0320u	/* P35 */
#define PDL_IO_PORT_3_6 0x0340u	/* P36 */
#define PDL_IO_PORT_3_7 0x0380u	/* P37 */

#define PDL_IO_PORT_4_0 0x0401u	/* P40 */
#define PDL_IO_PORT_4_1 0x0402u	/* P41 */
#define PDL_IO_PORT_4_2 0x0404u	/* P42 */
#define PDL_IO_PORT_4_3 0x0408u	/* P43 */
#define PDL_IO_PORT_4_4 0x0410u	/* P44 */
#define PDL_IO_PORT_4_5 0x0420u	/* P45 */
#define PDL_IO_PORT_4_6 0x0440u	/* P46 */
#define PDL_IO_PORT_4_7 0x0480u	/* P47 */

#define PDL_IO_PORT_5_0 0x0501u	/* P50 */
#define PDL_IO_PORT_5_1 0x0502u	/* P51 */
#define PDL_IO_PORT_5_2 0x0504u	/* P52 */
#define PDL_IO_PORT_5_3 0x0508u	/* P53 */
#define PDL_IO_PORT_5_4 0x0510u	/* P54 */
#define PDL_IO_PORT_5_5 0x0520u	/* P55 */

#define PDL_IO_PORT_A_0 0x0A01u	/* PA0 */
#define PDL_IO_PORT_A_1 0x0A02u	/* PA1 */
#define PDL_IO_PORT_A_2 0x0A04u	/* PA2 */
#define PDL_IO_PORT_A_3 0x0A08u	/* PA3 */
#define PDL_IO_PORT_A_4 0x0A10u	/* PA4 */
#define PDL_IO_PORT_A_5 0x0A20u	/* PA5 */
#define PDL_IO_PORT_A_6 0x0A40u	/* PA6 */
#define PDL_IO_PORT_A_7 0x0A80u	/* PA7 */

#define PDL_IO_PORT_B_0 0x0B01u	/* PB0 */
#define PDL_IO_PORT_B_1 0x0B02u	/* PB1 */
#define PDL_IO_PORT_B_2 0x0B04u	/* PB2 */
#define PDL_IO_PORT_B_3 0x0B08u	/* PB3 */
#define PDL_IO_PORT_B_4 0x0B10u	/* PB4 */
#define PDL_IO_PORT_B_5 0x0B20u	/* PB5 */
#define PDL_IO_PORT_B_6 0x0B40u	/* PB6 */
#define PDL_IO_PORT_B_7 0x0B80u	/* PB7 */

#define PDL_IO_PORT_C_0 0x0C01u	/* PC0 */
#define PDL_IO_PORT_C_1 0x0C02u	/* PC1 */
#define PDL_IO_PORT_C_2 0x0C04u	/* PC2 */
#define PDL_IO_PORT_C_3 0x0C08u	/* PC3 */
#define PDL_IO_PORT_C_4 0x0C10u	/* PC4 */
#define PDL_IO_PORT_C_5 0x0C20u	/* PC5 */
#define PDL_IO_PORT_C_6 0x0C40u	/* PC6 */
#define PDL_IO_PORT_C_7 0x0C80u	/* PC7 */

#define PDL_IO_PORT_D_0 0x0D01u	/* PD0 */
#define PDL_IO_PORT_D_1 0x0D02u	/* PD1 */
#define PDL_IO_PORT_D_2 0x0D04u	/* PD2 */
#define PDL_IO_PORT_D_3 0x0D08u	/* PD3 */
#define PDL_IO_PORT_D_4 0x0D10u	/* PD4 */
#define PDL_IO_PORT_D_5 0x0D20u	/* PD5 */
#define PDL_IO_PORT_D_6 0x0D40u	/* PD6 */
#define PDL_IO_PORT_D_7 0x0D80u	/* PD7 */

#define PDL_IO_PORT_E_0 0x0E01u	/* PE0 */
#define PDL_IO_PORT_E_1 0x0E02u	/* PE1 */
#define PDL_IO_PORT_E_2 0x0E04u	/* PE2 */
#define PDL_IO_PORT_E_3 0x0E08u	/* PE3 */
#define PDL_IO_PORT_E_4 0x0E10u	/* PE4 */
#define PDL_IO_PORT_E_5 0x0E20u	/* PE5 */
#define PDL_IO_PORT_E_6 0x0E40u	/* PE6 */
#define PDL_IO_PORT_E_7 0x0E80u	/* PE7 */

#define PDL_IO_PORT_H_0 0x1101u	/* PH0 */
#define PDL_IO_PORT_H_1 0x1102u	/* PH1 */
#define PDL_IO_PORT_H_2 0x1104u	/* PH2 */
#define PDL_IO_PORT_H_3 0x1108u	/* PH3 */

#define PDL_IO_PORT_J_1 0x1202u	/* PJ1 */
#define PDL_IO_PORT_J_3 0x1208u	/* PJ3 */

/* Settings */
#define PDL_IO_PORT_INPUT			0x0001u	/* Input port */
#define PDL_IO_PORT_OUTPUT			0x0002u	/* Output port */
#define PDL_IO_PORT_TYPE_CMOS		0x0004u	/* CMOS output */
#define PDL_IO_PORT_TYPE_NMOS		0x0008u	/* NMOS open-drain output */
#define PDL_IO_PORT_TYPE_PMOS		0x0010u	/* PMOS open-drain output */
#define PDL_IO_PORT_TYPE_HI_Z		0x0020u	/* High impedance */
#define PDL_IO_PORT_PULL_UP_ON		0x0040u	/* Pulled high */
#define PDL_IO_PORT_PULL_UP_OFF		0x0080u	/* Not pulled high */
#define PDL_IO_PORT_DRIVE_NORMAL	0x0100u	/* Pulled high */
#define PDL_IO_PORT_DRIVE_HIGH		0x0200u	/* Not pulled high */

/* Control register selection */
#define PDL_IO_PORT_DIRECTION	0x01u
#define PDL_IO_PORT_MODE		0x02u
#define PDL_IO_PORT_TYPE		0x04u
#define PDL_IO_PORT_PULL_UP		0x08u
#define PDL_IO_PORT_DRIVE		0x10u

/* Logical operations */
#define PDL_IO_PORT_AND			0x20u
#define PDL_IO_PORT_OR			0x40u
#define PDL_IO_PORT_XOR			0x80u

#endif
/* End of file */
