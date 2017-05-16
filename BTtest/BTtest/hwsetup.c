/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*******************************************************************************/
/* Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.   */
/*******************************************************************************
* File Name		: hwsetup.c
* Version 		: 1.00
* Device 		: R5F52108DFP
* Tool-Chain 	: RX Family C Compiler, v1.01
* H/W Platform	: RSKRX210
* Description   : Defines the hardware initialisation routines used each time 
*				  the MCU is restarted. 
*******************************************************************************/
/*******************************************************************************
* History 		: 05.08.2011  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* IO Port RPDL function definitions */
#include "r_pdl_io_port.h"
/* CGC RPDL function definitions */
#include "r_pdl_cgc.h"
/* General RPDL function definitions */
#include "r_pdl_definitions.h"
/* Switch handler function definitions */
#include "switch.h"
/* Contains declarations for the functions defined in this file */
#include "hwsetup.h"

/*******************************************************************************
* Outline 		: HardwareSetup
* Description 	: Contains all the setup functions called at device restart
* Argument 	 	: none
* Return value  : none
*******************************************************************************/
void HardwareSetup(void)
{
	ConfigureOperatingFrequency();
	ConfigureOutputPorts();
	ConfigureInterrupts();
	EnablePeripheralModules();
}
/*******************************************************************************
* End of function HardwareSetup
*******************************************************************************/

/*******************************************************************************
* Outline 		: ConfigureOperatingFrequency
* Description 	: Configures the clock settings for each of the device clocks
* Argument 	 	: none
* Return value  : none
*******************************************************************************/
void ConfigureOperatingFrequency(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Configure the PLL to use the 20.0 MHz crystal as clock input */
	err &= 	R_CGC_Set
			(
				PDL_CGC_CLK_MAIN,
				PDL_CGC_BCLK_DIV_1 | PDL_CGC_MAIN_EXTERNAL,
				20E6,
				20E6,
				20E6,
				20E6,
				20E6,
				PDL_NO_DATA
			);
			
	/* Configure the clocks as follows -
	Clock Description              Frequency
	----------------------------------------
	PLL Clock frequency...............100MHz
	System Clock Frequency.............50MHz
	Peripheral Module Clock B..........25MHz 
	Peripheral Module Clock D..........50MHz 	
	FlashIF Clock......................25MHz
	External Bus Clock.................25MHz */	
	
	err &= 	R_CGC_Set	
			(
				PDL_CGC_CLK_PLL,
				PDL_CGC_BCLK_DIV_2,
				100E6,
				50E6,
				50E6,
				25E6,
				25E6,
				25E6
			);
	
	/* Allow 100us for the main clock to stabilise */
	err &=  R_CMT_CreateOneShot
			(
				0,
				PDL_NO_DATA,
				100E-6,
				PDL_NO_FUNC,
				0
			);
	
	/* Select the PLL as the clock source */
	err &= R_CGC_Control
			(
				PDL_CGC_CLK_PLL,
				PDL_NO_DATA,
				PDL_NO_DATA
			);
				
	/* Halt in while loop when RPDL errors detected */
	while(!err);	
}
/*******************************************************************************
* End of function ConfigureOperatingFrequency
*******************************************************************************/

/*******************************************************************************
* Outline 		: ConfigureOutputPorts
* Description 	: Configures the port and pin direction settings, and sets the
*				  pin outputs to a safe level.
* Argument  	: none
* Return value  : none
*******************************************************************************/
void ConfigureOutputPorts(void)
{
	/* Declare error flag */
	bool err = true;
	
    /* Configure the LED pins (LED0-LED3) as outputs */
	err &=	R_IO_PORT_Set
			(
				PDL_IO_PORT_1_4|PDL_IO_PORT_1_5|PDL_IO_PORT_1_6|PDL_IO_PORT_1_7,
				PDL_IO_PORT_OUTPUT
			);

	/* Set LED pin outputs as high (all LEDs off) */
	err &= R_IO_PORT_Write
			(
				PDL_IO_PORT_1_4|PDL_IO_PORT_1_5|PDL_IO_PORT_1_6|PDL_IO_PORT_1_7,
				1
			);
	
    /* Configure the debug LCD data pins (DLCD7-DLCD4) as outputs */
    err &=	R_IO_PORT_Set
			(
				PDL_IO_PORT_H_0|PDL_IO_PORT_H_1|PDL_IO_PORT_H_2|
				PDL_IO_PORT_H_3,
				PDL_IO_PORT_OUTPUT
			);
			
	/* Set debug LCD data pin (DLCD7-DLCD4) outputs as low */
	err &=	R_IO_PORT_Write
			(
				PDL_IO_PORT_H_0|PDL_IO_PORT_H_1|PDL_IO_PORT_H_2|
				PDL_IO_PORT_H_3,
				0
			);
	
	/* Configure the debug LCD control pin (DLCDRS) and enable pin (DLCDE)
	   as output */
	err &=	R_IO_PORT_Set
			(
				PDL_IO_PORT_J_1|PDL_IO_PORT_J_3,
				PDL_IO_PORT_OUTPUT
			);
			
	/* Set the debug LCD control pin (DLCDRS) and enable pin (DLCDE) as output
	   low */
	err &=	R_IO_PORT_Write
			(
				PDL_IO_PORT_J_1|PDL_IO_PORT_J_3,
				0
			);
	
	/* Halt in while loop when RPDL errors detected */
	while(!err);	
}
/*******************************************************************************
* End of function ConfigureOutputPorts
*******************************************************************************/

/*******************************************************************************
* Outline 		: ConfigureInterrupts
* Description 	: Configures the interrupts used
* Argument  	: none
* Return value  : none
*******************************************************************************/
void ConfigureInterrupts(void)
{
	/* Configure switch interrupts */
	InitialiseSwitchInterrupts();
}
/*******************************************************************************
* End of function ConfigureInterrupts
*******************************************************************************/

/*******************************************************************************
* Outline 		: EnablePeripheralModules
* Description 	: Enables and configures peripheral devices on the MCU
* Argument  	: none
* Return value  : none
*******************************************************************************/
void EnablePeripheralModules(void)
{
	/* The required modules will be enabled by the RPDL functions.	*/
}
/*******************************************************************************
* End of function EnablePeripheralModules
*******************************************************************************/
