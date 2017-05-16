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
* File Name		: switch.c
* Version 		: 1.00
* Device 		: R5F52108DFP
* Tool-Chain 	: RX Family C Compiler, v1.01
* H/W Platform	: RSKRX210
* Description   : Defines interrupt service routine functions for the switch
*				  interrupts. De-bounces switch and sets a key press flag. 
*******************************************************************************/
/*******************************************************************************
* History 		: 05.08.2011  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* INTC RPDL function definitions */
#include "r_pdl_intc.h"
/* CMT RPDL function definitions */
#include "r_pdl_cmt.h"
/* General RPDL function definitions */
#include "r_pdl_definitions.h"
/* Switch handler function definitions */
#include "switch.h"

/*******************************************************************************
* Global Variables
*******************************************************************************/
/* Switch flag global variable */
volatile uint8_t gSwitchFlag = 0x00;
/* Switch standby ready global variable */
volatile bool gSwitchStandbyReady = true;
/* Switch press callback pointer declaration */
void (*gSwitchPressCallbackFunc)(void) = NULL;
/* Switch release callback pointer declaration */
void (*gSwitchReleaseCallbackFunc)(void) = NULL;

/*******************************************************************************
* Local Function Prototypes
*******************************************************************************/
/* Switch 1 interrupt callback function prototype */
void SW1_InterruptCB(void);
/* Switch 2 interrupt callback function prototype */
void SW2_InterruptCB(void);
/* Switch 3 interrupt callback function prototype */
void SW3_InterruptCB(void);
/* Switch de-bounce callback function prototype */
void SwitchDebounceCB(void);

/*******************************************************************************
* Outline 		: InitialiseSwitchInterrupts
* Description 	: Configures the IRQ pins connected to switches SW1-SW3 to
*				  detect switch presses, and invoke an ISR.
* Argument 	 	: none
* Return value  : none
*******************************************************************************/
void InitialiseSwitchInterrupts(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Reset the switch flag */
	gSwitchFlag = 0x00;
	
	/* Reset the switch standby ready flag */
	gSwitchStandbyReady = true;
	
	/* Select the IRQ pins to be used for interrupts */
	err &=	R_INTC_SetExtInterrupt
			(
				PDL_INTC_IRQ1_PORT_3_1|PDL_INTC_IRQ3_PORT_3_3|\
				PDL_INTC_IRQ4_PORT_3_4
			);
	
	/* Configure IRQ1 interrupt (connected to SW1) */
	err &=	R_INTC_CreateExtInterrupt
			(
				PDL_INTC_IRQ1,
				PDL_INTC_FALLING,
				SW1_InterruptCB,
				7
			);
							  
	/* Configure IRQ3 interrupt (connected to SW2) */
	err &= 	R_INTC_CreateExtInterrupt
			(
				PDL_INTC_IRQ3,
				PDL_INTC_FALLING, 
				SW2_InterruptCB,
				7
			);
							 
	/* Configure IRQ4 interrupt (connected to SW3) */
	err &=	R_INTC_CreateExtInterrupt
			(
				PDL_INTC_IRQ4,
				PDL_INTC_FALLING, 
				SW3_InterruptCB,
				7
			);			
	
	/* Halt in while loop when RPDL errors detected */	
	while(!err);
}
/******************************************************************************
* End of InitialiseSwitchInterrupts
******************************************************************************/

/******************************************************************************
* Outline 		: SetSwitchPressCallback
* Description 	: Takes a pointer to a function, and sets it as the callback
*				  function for the switch interrupts. The passed function is
*				  executed every time any switch is pressed down.
* Argument  	: pointer to callback function (set to NULL to disable)
* Return value  : none
******************************************************************************/
void SetSwitchPressCallback(void(*callback)(void))
{
	/* Store the callback function pointer into the global variable */
	gSwitchPressCallbackFunc = callback;
}
/******************************************************************************
* End of SetSwitchPressCallback
******************************************************************************/

/******************************************************************************
* Outline 		: SetSwitchReleaseCallback
* Description 	: Takes a pointer to a function, and sets it as the callback
*				  function for the switch interrupts. The passed function is
*				  executed every time any switch is released.
* Argument  	: pointer to callback function (set to NULL to disable)
* Return value  : none
******************************************************************************/
void SetSwitchReleaseCallback(void(*callback)(void))
{
	/* Store the callback function pointer into the global variable */
	gSwitchReleaseCallbackFunc = callback;
}
/******************************************************************************
* End of SetSwitchReleaseCallback
******************************************************************************/

/******************************************************************************
* Outline 		: ControlSwitchInterrupts
* Description 	: Enables or disables the switch IRQ interrupts, based on the
*				  input variable, control.
* Argument  	: bool - true  : Enables switch interrupts.
*						 false : Disables switch interrupts.
* Return value  : none
******************************************************************************/
void ControlSwitchInterrupts(bool control)
{
	/* Declare error flag */
	bool err = true;
	
	/* Check if control input is true */
	if(control)
	{
		/* Enable SW1 interrupts */
		err &= 	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ1,
					PDL_INTC_ENABLE|PDL_INTC_FALLING
				);
	
		/* Enable SW2 interrupts */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ3,
					PDL_INTC_ENABLE|PDL_INTC_FALLING
				);
	
		/* Enable SW3 interrupts */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ4,
					PDL_INTC_ENABLE|PDL_INTC_FALLING
				);
	}
	/* Control input is false */
	else
	{	
		/* Disable SW1 interrupts */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ1,
					PDL_INTC_DISABLE
				);
		
		/* Disable SW2 interrupts */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ3,
					PDL_INTC_DISABLE
				);
	
		/* Disable SW3 interrupts */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ4,
					PDL_INTC_DISABLE
				);
	}
	
	/* Halt in while loop when RPDL errors detected */	
	while(!err);	
}	
/******************************************************************************
* End of function ControlSwitchInterrupts
******************************************************************************/	
	
/******************************************************************************
* Outline 		: SW1_InterruptCB
* Description 	: Switch 1 callback ISR function. The function disables switch
*				  interrupts, then uses a one-shot timer to re-enable them after
*				  a 10ms de-bounce timer period.
* Argument  	: none
* Return value  : none
******************************************************************************/
void SW1_InterruptCB(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Declare status container variable */
	uint8_t status = 0x00;
	
	/* Fetch input edge status */
	err &=	R_INTC_GetExtInterruptStatus
			(
				PDL_INTC_IRQ1,
				&status
			);
	
	/* Check if interrupt was triggered from falling edge */
	if((status & 0x0C) == 0x04)
	{
		/* Disable switch interrupts and change to rising edge detection */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ1,
					PDL_INTC_DISABLE|PDL_INTC_RISING
				);
			
		/* Set global switch flag to indicate SW1 is held down */
		gSwitchFlag |= 0x08;
		
		/* Check if switch press callback function is not NULL */
		if(gSwitchPressCallbackFunc)
		{
			/* Execute user callback function */
			gSwitchPressCallbackFunc();
		}
	}

	/* Interrupt was triggered from a rising edge */
	else
	{	
		/* Disable switch interrupts and change to falling edge detection */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ1,
					PDL_INTC_DISABLE|PDL_INTC_FALLING
				);

		/* Clear SW1 held-down flag bit in switch flag */
		gSwitchFlag &= 0xF7;
		
		/* Set global switch flag to indicate SW1 press complete */
		gSwitchFlag |= 0x80;
	
		/* Check if switch release callback function is not NULL */
		if(gSwitchReleaseCallbackFunc)
		{
			/* Execute user callback function */
			gSwitchReleaseCallbackFunc();
		}
	}	

	/* Set standby ready flag as false */
	gSwitchStandbyReady = false;

	/* Create 10ms one-shot timer interrupt to de-bounce the switch input */
	err &=	R_CMT_CreateOneShot
			(
				1,
				PDL_NO_DATA,
				10E-3,
				SwitchDebounceCB,
				8
			);
	
	/* Halt in while loop when RPDL errors detected */	
	while(!err);
}
/******************************************************************************
* End of function SW1_InterruptCB
******************************************************************************/	

/******************************************************************************
* Outline 		: SW2_InterruptCB
* Description 	: Switch 2 callback ISR function. The function disables switch
*				  interrupts, then uses a oneshot timer to re-enable them after
*				  a 10ms de-bounce timer period.
* Argument 	 	: none
* Return value  : none
******************************************************************************/
void SW2_InterruptCB(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Declare status container variable */
	uint8_t status = 0x00;
	
	/* Fetch input edge status */
	err &=	R_INTC_GetExtInterruptStatus
			(
				PDL_INTC_IRQ3,
				&status
			);
		
	/* Check if interrupt was triggered from falling edge */
	if((status & 0x0C) == 0x04)
	{
		/* Disable switch interrupts and change to rising edge detection */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ3,
					PDL_INTC_DISABLE|PDL_INTC_RISING
				);

		/* Set global switch flag to indicate SW2 is held down */
		gSwitchFlag |= 0x04;
	
		/* Check if switch press callback function is not NULL */
		if(gSwitchPressCallbackFunc)
		{
			/* Execute user callback function */
			gSwitchPressCallbackFunc();
		}
	}
	else
	{
		/* Disable switch interrupts and change to falling edge detection */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ3,
					PDL_INTC_DISABLE|PDL_INTC_FALLING
				);

		/* Clear SW2 held-down bit in switch flag */
		gSwitchFlag &= 0xFB;
	
		/* Set global switch flag to indicate SW2 press complete */
		gSwitchFlag |= 0x40;
	
		/* Check if switch release callback function is not NULL */
		if(gSwitchReleaseCallbackFunc)
		{
			/* Execute user callback function */
			gSwitchReleaseCallbackFunc();
		}
	}	
	
	/* Set standby ready flag as false */
	gSwitchStandbyReady = false;
	
	/* Create 10ms one-shot timer interrupt to de-bounce the switch input */
	err &=	R_CMT_CreateOneShot
			(
				1,
				PDL_NO_DATA,
				10E-3,
				SwitchDebounceCB,
				8
			);
	
	/* Halt in while loop when RPDL errors detected */	
	while(!err);
}
/******************************************************************************
* End of function SW2_InterruptCB
******************************************************************************/	

/******************************************************************************
* Outline 		: SW3_InterruptCB
* Description 	: Switch 3 callback ISR function. The function disables switch
*				  interrupts, then uses a oneshot timer to re-enable them after
*				  a 10ms de-bounce timer period.
* Argument  	: none
* Return value  : none
******************************************************************************/
void SW3_InterruptCB(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Declare status container variable */
	uint8_t status = 0x00;
	
	/* Fetch input edge status */
	err &=	R_INTC_GetExtInterruptStatus
			(
				PDL_INTC_IRQ4,
				&status
			);
	
	/* Check if interrupt was triggered from falling edge */
	if((status & 0x0C) == 0x04)
	{
		/* Disable switch interrupts and change to rising edge detection */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ4,
					PDL_INTC_DISABLE|PDL_INTC_RISING
				);
		
		/* Set global switch flag to indicate SW3 is held down */
		gSwitchFlag |= 0x02;
	
		/* Check if switch press callback function is not NULL */
		if(gSwitchPressCallbackFunc)
		{
			/* Execute user callback function */
			gSwitchPressCallbackFunc();
		}
	}

	else
	{
		/* Switch to falling edge detection */
		err &=	R_INTC_ControlExtInterrupt
				(
					PDL_INTC_IRQ4,
					PDL_INTC_FALLING
				);

		/* Clear SW3 held-down bit in switch flag */
		gSwitchFlag &= 0xFD;
	
		/* Set global switch flag to indicate SW3 press complete */
		gSwitchFlag |= 0x20;
		
		/* Check if switch release callback function is not NULL */
		if(gSwitchReleaseCallbackFunc)
		{
			/* Execute user callback function */
			gSwitchReleaseCallbackFunc();
		}
	}

	/* Set standby ready flag as false */
	gSwitchStandbyReady = false;

	/* Create 10ms one-shot timer interrupt to de-bounce the switch input */
	err &=	R_CMT_CreateOneShot
			(
				1,
				PDL_NO_DATA,
				10E-3,
				SwitchDebounceCB,
				8
			);

	/* Halt in while loop when RPDL errors detected */	
	while(!err);
}
/******************************************************************************
* End of function SW3_InterruptCB
******************************************************************************/	

/******************************************************************************
* Outline 		: SwitchDebounceCB
* Description 	: One-shot timer callback function. This function is triggered
*				  by the timer interrupt, and re-enables switch interrupts.
* Argument 	 	: none
* Return value  : none
******************************************************************************/
void SwitchDebounceCB(void)
{
	/* Declare error flag */
	bool err = true;
	
	/* Check if any switches are held down */
	if(!(gSwitchFlag & SWITCHHOLD_ALL))
	{
		/* Set standby ready flag to true */
		gSwitchStandbyReady = true;
	}
	
	/* Re-enable switch 1 interrupts */
	err &=	R_INTC_ControlExtInterrupt
			(
				PDL_INTC_IRQ1,
				PDL_INTC_ENABLE|PDL_INTC_CLEAR_IR_FLAG 
			);
	
	/* Re-enable switch 2 interrupts */
	err &=	R_INTC_ControlExtInterrupt
			(
				PDL_INTC_IRQ3,
				PDL_INTC_ENABLE|PDL_INTC_CLEAR_IR_FLAG 
			);
	
	/* Re-enable switch 3 interrupts */
	err &=	R_INTC_ControlExtInterrupt
			(
				PDL_INTC_IRQ4,
				PDL_INTC_ENABLE|PDL_INTC_CLEAR_IR_FLAG 
			);
		
	/* Halt in while loop when RPDL errors detected */	
	while(!err);
}
/******************************************************************************
* End of function SwitchDebounceCB
******************************************************************************/
