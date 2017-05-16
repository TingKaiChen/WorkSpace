/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX210
* File Name		: Interrupt_SCI.c
* Version		: 0.20
* Contents		: Interrupt handlers for all SCI channels
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

#include "r_pdl_sci.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/* This file uses some SCI utility functions */
extern bool rpdl_SCI_SetTxPinGeneralIO(const uint8_t channel,
									   const bool bGeneralIO);
extern void rpdl_SCI_ModifyTx_IER(const uint8_t, const uint8_t);
extern void rpdl_SCI_ModifyTxEnd_IER(const uint8_t, const uint8_t);
extern void R_SCI_IIC_Handler_RXI(const uint8_t channel);
extern void R_SCI_IIC_Handler_TXI(const uint8_t channel);

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn receive data error interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_ERIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: SSR for that SCI channel
*-------------------------------------------------------------------
* Use function	: rpdl_SCI_RX_Error_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_ERI0
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0, fint)
#else
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0)
#endif
void Interrupt_SCI0_ERI0(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(0)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(0)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI0.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI0.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_ERI1
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1, fint)
#else
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1)
#endif
void Interrupt_SCI1_ERI1(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(1)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(1)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI1.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI1.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI5_ERI5
#pragma interrupt Interrupt_SCI5_ERI5(vect=VECT_SCI5_ERI5, fint)
#else
#pragma interrupt Interrupt_SCI5_ERI5(vect=VECT_SCI5_ERI5)
#endif
void Interrupt_SCI5_ERI5(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(5)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(5)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI5.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI5.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_ERI6
#pragma interrupt Interrupt_SCI6_ERI6(vect=VECT_SCI6_ERI6, fint)
#else
#pragma interrupt Interrupt_SCI6_ERI6(vect=VECT_SCI6_ERI6)
#endif
void Interrupt_SCI6_ERI6(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(6)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(6)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI6.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI6.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI8_ERI8
#pragma interrupt Interrupt_SCI8_ERI2(vect=VECT_SCI8_ERI8, fint)
#else
#pragma interrupt Interrupt_SCI8_ERI8(vect=VECT_SCI8_ERI8)
#endif
void Interrupt_SCI8_ERI8(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(8)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(8)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI8.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI8.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI9_ERI9
#pragma interrupt Interrupt_SCI9_ERI9(vect=VECT_SCI9_ERI9, fint)
#else
#pragma interrupt Interrupt_SCI9_ERI9(vect=VECT_SCI9_ERI9)
#endif
void Interrupt_SCI9_ERI9(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(9)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(9)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI9.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI9.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI12_ERI12
#pragma interrupt Interrupt_SCI12_ERI12(vect=VECT_SCI12_ERI12, fint)
#else
#pragma interrupt Interrupt_SCI12_ERI12(vect=VECT_SCI12_ERI12)
#endif
void Interrupt_SCI12_ERI12(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_GlobalData(12)->RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_GlobalData(12)->RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI12.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |
						 (SCI12.SSR.BYTE & (uint8_t)BIT_0));
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn receive data interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_RXIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_SCI_RX_End_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_RXI0
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0)
#endif
void Interrupt_SCI0_RXI0(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI0.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(0);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(0)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(0)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI0.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI0.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(0)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI0.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(0)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(0)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(0)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*rpdl_SCI_GlobalData(0)->rx_string_pointer = SCI0.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(0)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(0)->rx_counter < rpdl_SCI_GlobalData(0)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(0)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI0.SMR.BIT.CM == 1) &&
			   ((SCI0.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI0.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(0)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI0.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(0)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(0)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(0)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(0)->RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_RXI1
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1, fint)
#else
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1)
#endif
void Interrupt_SCI1_RXI1(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI1.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(1);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(1)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(1)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI1.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI1.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(1)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI1.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(1)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(1)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(1)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*rpdl_SCI_GlobalData(1)->rx_string_pointer = SCI1.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(1)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(1)->rx_counter < rpdl_SCI_GlobalData(1)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(1)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI1.SMR.BIT.CM == 1) &&
			   ((SCI1.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
		
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI1.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(1)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI1.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(1)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(1)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(1)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(1)->RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI5_RXI5
#pragma interrupt Interrupt_SCI5_RXI5(vect=VECT_SCI5_RXI5, fint)
#else
#pragma interrupt Interrupt_SCI5_RXI5(vect=VECT_SCI5_RXI5)
#endif
void Interrupt_SCI5_RXI5(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI5.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(5);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(5)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(5)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI5.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI5.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(5)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI5.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(5)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(5)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(5)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*rpdl_SCI_GlobalData(5)->rx_string_pointer = SCI5.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(5)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(5)->rx_counter < rpdl_SCI_GlobalData(5)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(5)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI5.SMR.BIT.CM == 1) &&
			   ((SCI5.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
		
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI5.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(5)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI5.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(5)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(5)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(5)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(5)->RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_RXI6
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6)
#endif
void Interrupt_SCI6_RXI6(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI6.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(6);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(6)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(6)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI6.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI6.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(6)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI6.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(6)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(6)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(6)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*rpdl_SCI_GlobalData(6)->rx_string_pointer = SCI6.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(6)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(6)->rx_counter < rpdl_SCI_GlobalData(6)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(6)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI6.SMR.BIT.CM == 1) &&
			   ((SCI6.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
		
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI6.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(6)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI6.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(6)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(6)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(6)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(6)->RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI8_RXI8
#pragma interrupt Interrupt_SCI8_RXI8(vect=VECT_SCI8_RXI8, fint)
#else
#pragma interrupt Interrupt_SCI8_RXI8(vect=VECT_SCI8_RXI8)
#endif
void Interrupt_SCI8_RXI8(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI8.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(8);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(8)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(8)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI8.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI8.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(8)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI8.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI8.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(8)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(8)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(8)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*rpdl_SCI_GlobalData(8)->rx_string_pointer = SCI8.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(8)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(8)->rx_counter < rpdl_SCI_GlobalData(8)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(8)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI8.SMR.BIT.CM == 1) &&
			   ((SCI8.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
		
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI8.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI8.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI8.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(8)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI8.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(8)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(8)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(8)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(8)->RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI9_RXI9
#pragma interrupt Interrupt_SCI9_RXI9(vect=VECT_SCI9_RXI9, fint)
#else
#pragma interrupt Interrupt_SCI9_RXI9(vect=VECT_SCI9_RXI9)
#endif
void Interrupt_SCI9_RXI9(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI9.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(9);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(9)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(9)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI9.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI9.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(9)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI9.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI9.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(9)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(9)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(9)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*rpdl_SCI_GlobalData(9)->rx_string_pointer = SCI9.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(9)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(9)->rx_counter < rpdl_SCI_GlobalData(9)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(9)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI9.SMR.BIT.CM == 1) &&
			   ((SCI9.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
		
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI9.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI9.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI9.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(9)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI9.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(9)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(9)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(9)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(9)->RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI12_RXI12
#pragma interrupt Interrupt_SCI12_RXI12(vect=VECT_SCI12_RXI12, fint)
#else
#pragma interrupt Interrupt_SCI12_RXI12(vect=VECT_SCI12_RXI12)
#endif
void Interrupt_SCI12_RXI12(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI12.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_RXI(12);
		return;
	}
	
	/* Ok to process the data? */
	if (rpdl_SCI_GlobalData(12)->rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_GlobalData(12)->MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI12.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI12.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_GlobalData(12)->MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI12.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI12.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					rpdl_SCI_GlobalData(12)->MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (rpdl_SCI_GlobalData(12)->RX_End_callback_func != PDL_NO_FUNC)
					{
						rpdl_SCI_GlobalData(12)->RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*rpdl_SCI_GlobalData(12)->rx_string_pointer = SCI12.RDR;

		/* Increment the character counter */
		rpdl_SCI_GlobalData(12)->rx_counter++;

		/* More characters expected? */
		if (rpdl_SCI_GlobalData(12)->rx_counter < rpdl_SCI_GlobalData(12)->rx_threshold)
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_GlobalData(12)->rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.
			If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0) also clear TE*/
			if((SCI12.SMR.BIT.CM == 1) &&
			   ((SCI12.SCR.BYTE & (BIT_5 | BIT_7)) == BIT_5))
		
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI12.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* Disable interrupt request generation, and try to disable reception */
				SCI12.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
			}

			/* Async MP mode ? */
			if (((SCI12.SMR.BIT.MP) != 0) &&
				(rpdl_SCI_GlobalData(12)->MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI12.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_GlobalData(12)->RX_End_callback_func != PDL_NO_FUNC)
			{
				rpdl_SCI_GlobalData(12)->RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(12)->RX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(12)->RX_End_callback_func();
		}
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn transmit data interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_TXIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: TDR for that SCI channel
*-------------------------------------------------------------------
* Use function	: 
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_TXI0
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0)
#endif
void Interrupt_SCI0_TXI0(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI0.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(0);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(0)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(0)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(0)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(0)->tx_counter < rpdl_SCI_GlobalData(0)->tx_threshold)
		)
		{
			/* Send the character */
			SCI0.TDR = *rpdl_SCI_GlobalData(0)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(0)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(0)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(0)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(0)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(0)->tx_counter == rpdl_SCI_GlobalData(0)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI0.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI0.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(0, 0);
					
					/*Enable Transmit End Interrupt */
					SCI0.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(0, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI0.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI0.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(0)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(0)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(0)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(0)->TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_TXI1
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1, fint)
#else
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1)
#endif
void Interrupt_SCI1_TXI1(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI1.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(1);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(1)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(1)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(1)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(1)->tx_counter < rpdl_SCI_GlobalData(1)->tx_threshold)
		)
		{
			/* Send the character */
			SCI1.TDR = *rpdl_SCI_GlobalData(1)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(1)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(1)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(1)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(1)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(1)->tx_counter == rpdl_SCI_GlobalData(1)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI1.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI1.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(1, 0);
					
					/*Enable Transmit End Interrupt */
					SCI1.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(1, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI1.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI1.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(1)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(1)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(1)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(1)->TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI5_TXI5
#pragma interrupt Interrupt_SCI5_TXI5(vect=VECT_SCI5_TXI5, fint)
#else
#pragma interrupt Interrupt_SCI5_TXI5(vect=VECT_SCI5_TXI5)
#endif
void Interrupt_SCI5_TXI5(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI5.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(5);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(5)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(5)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(5)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(5)->tx_counter < rpdl_SCI_GlobalData(5)->tx_threshold)
		)
		{
			/* Send the character */
			SCI5.TDR = *rpdl_SCI_GlobalData(5)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(5)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(5)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(5)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(5)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(5)->tx_counter == rpdl_SCI_GlobalData(5)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI5.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI5.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(5, 0);
					
					/*Enable Transmit End Interrupt */
					SCI5.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(5, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI5.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI5.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(5)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(5)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(5)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(5)->TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_TXI6
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6)
#endif
void Interrupt_SCI6_TXI6(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI6.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(6);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(6)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(6)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(6)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(6)->tx_counter < rpdl_SCI_GlobalData(6)->tx_threshold)
		)
		{
			/* Send the character */
			SCI6.TDR = *rpdl_SCI_GlobalData(6)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(6)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(6)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(6)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(6)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(6)->tx_counter == rpdl_SCI_GlobalData(6)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI6.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI6.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(6, 0);
					
					/*Enable Transmit End Interrupt */
					SCI6.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(6, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI6.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI6.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(6)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(6)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(6)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(6)->TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI8_TXI8
#pragma interrupt Interrupt_SCI8_TXI8(vect=VECT_SCI8_TXI8, fint)
#else
#pragma interrupt Interrupt_SCI8_TXI8(vect=VECT_SCI8_TXI8)
#endif
void Interrupt_SCI8_TXI8(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI8.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(8);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(8)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(8)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(8)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(8)->tx_counter < rpdl_SCI_GlobalData(8)->tx_threshold)
		)
		{
			/* Send the character */
			SCI8.TDR = *rpdl_SCI_GlobalData(8)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(8)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(8)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(8)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(8)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(8)->tx_counter == rpdl_SCI_GlobalData(8)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI8.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI8.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(8, 0);
					
					/*Enable Transmit End Interrupt */
					SCI8.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(8, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI8.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI8.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI8.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(8)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(8)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(8)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(8)->TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI9_TXI9
#pragma interrupt Interrupt_SCI9_TXI9(vect=VECT_SCI9_TXI9, fint)
#else
#pragma interrupt Interrupt_SCI9_TXI9(vect=VECT_SCI9_TXI9)
#endif
void Interrupt_SCI9_TXI9(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI9.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(9);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(9)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(9)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(9)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(9)->tx_counter < rpdl_SCI_GlobalData(9)->tx_threshold)
		)
		{
			/* Send the character */
			SCI9.TDR = *rpdl_SCI_GlobalData(9)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(9)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(9)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(9)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(9)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(9)->tx_counter == rpdl_SCI_GlobalData(9)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI9.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI9.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(9, 0);
					
					/*Enable Transmit End Interrupt */
					SCI9.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(9, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI9.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI9.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI9.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(9)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(9)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(9)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(9)->TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI12_TXI12
#pragma interrupt Interrupt_SCI12_TXI12(vect=VECT_SCI12_TXI12, fint)
#else
#pragma interrupt Interrupt_SCI12_TXI12(vect=VECT_SCI12_TXI12)
#endif
void Interrupt_SCI12_TXI12(void)
{
	/*If SCI is in IIC mode (SIMR1.IICM == 1)
	then handle this interrupt separately*/
	if(SCI12.SIMR1.BIT.IICM == 1)
	{
		R_SCI_IIC_Handler_TXI(12);
		return;
	}
	
	/* Ok to process the string? */
	if (rpdl_SCI_GlobalData(12)->tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_GlobalData(12)->tx_threshold == 0) && (*rpdl_SCI_GlobalData(12)->tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_GlobalData(12)->tx_counter < rpdl_SCI_GlobalData(12)->tx_threshold)
		)
		{
			/* Send the character */
			SCI12.TDR = *rpdl_SCI_GlobalData(12)->tx_string_pointer;

			/* Increment the pointer */
			rpdl_SCI_GlobalData(12)->tx_string_pointer++;

			/* Increment the counter */
			rpdl_SCI_GlobalData(12)->tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if(((rpdl_SCI_GlobalData(12)->tx_threshold == 0) &&
				(*rpdl_SCI_GlobalData(12)->tx_string_pointer == NULL)) ||
				(rpdl_SCI_GlobalData(12)->tx_counter == rpdl_SCI_GlobalData(12)->tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if(SCI12.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI12.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(12, 0);
					
					/*Enable Transmit End Interrupt */
					SCI12.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(12, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI12.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI12.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI12.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_GlobalData(12)->TX_End_callback_func != PDL_NO_FUNC)
				{
					rpdl_SCI_GlobalData(12)->TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_GlobalData(12)->TX_End_callback_func != PDL_NO_FUNC)
		{
			rpdl_SCI_GlobalData(12)->TX_End_callback_func();
		}
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn transmit end interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_TEIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: SCR for that channel
*-------------------------------------------------------------------
* Use function	: rpdl_SCI_TX_End_callback_func()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.08.12
*				: Ver 0.20
*				: WS2 release.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_TEI0
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0)
#endif
void Interrupt_SCI0_TEI0(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI0.SMR.BIT.CM == 1) &&
	   ((SCI0.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI0.SMR.BIT.CM == 0) && (SCI0.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(0, true);
	}

	/* Call the callback function */
	if (rpdl_SCI_GlobalData(0)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(0)->TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_TEI1
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1, fint)
#else
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1)
#endif
void Interrupt_SCI1_TEI1(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI1.SMR.BIT.CM == 1) &&
	   ((SCI1.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI1.SMR.BIT.CM == 0) && (SCI1.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(1, true);
	}

	/* Call the callback function */
	if (rpdl_SCI_GlobalData(1)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(1)->TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI5_TEI5
#pragma interrupt Interrupt_SCI5_TEI5(vect=VECT_SCI5_TEI5, fint)
#else
#pragma interrupt Interrupt_SCI5_TEI5(vect=VECT_SCI5_TEI5)
#endif
void Interrupt_SCI5_TEI5(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI5.SMR.BIT.CM == 1) &&
	   ((SCI5.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI5.SMR.BIT.CM == 0) && (SCI5.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(5, true);
	}

	/* Call the callback function */
	if (rpdl_SCI_GlobalData(5)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(5)->TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_TEI6
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6)
#endif
void Interrupt_SCI6_TEI6(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI6.SMR.BIT.CM == 1) &&
	   ((SCI6.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI6.SMR.BIT.CM == 0) && (SCI6.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(6, true);
	}

	/* Call the callback function */
	if (rpdl_SCI_GlobalData(6)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(6)->TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI8_TEI8
#pragma interrupt Interrupt_SCI8_TEI8(vect=VECT_SCI8_TEI8, fint)
#else
#pragma interrupt Interrupt_SCI8_TEI8(vect=VECT_SCI8_TEI8)
#endif
void Interrupt_SCI8_TEI8(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI8.SMR.BIT.CM == 1) &&
	   ((SCI8.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI8.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI8.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI8.SMR.BIT.CM == 0) && (SCI8.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(8, true);
	}
	
	/* Call the callback function */
	if (rpdl_SCI_GlobalData(8)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(8)->TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI9_TEI9
#pragma interrupt Interrupt_SCI9_TEI9(vect=VECT_SCI9_TEI9, fint)
#else
#pragma interrupt Interrupt_SCI9_TEI9(vect=VECT_SCI9_TEI9)
#endif
void Interrupt_SCI9_TEI9(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI9.SMR.BIT.CM == 1) &&
	   ((SCI9.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI9.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI9.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI9.SMR.BIT.CM == 0) && (SCI9.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(9, true);
	}
	
	/* Call the callback function */
	if (rpdl_SCI_GlobalData(9)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(9)->TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI12_TEI12
#pragma interrupt Interrupt_SCI12_TEI12(vect=VECT_SCI12_TEI12, fint)
#else
#pragma interrupt Interrupt_SCI12_TEI12(vect=VECT_SCI12_TEI12)
#endif
void Interrupt_SCI12_TEI12(void)
{
	/*Tx has finished.
	If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if((SCI12.SMR.BIT.CM == 1) &&
	   ((SCI12.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI12.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI12.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/*If In async mode (SMIF == 0 and CM == 0) to allow control of the
	Tx pin when idle, configure it as a general IO pin.*/
	if( (SCI12.SMR.BIT.CM == 0) && (SCI12.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(12, true);
	}

	/* Call the callback function */
	if (rpdl_SCI_GlobalData(12)->TX_End_callback_func != PDL_NO_FUNC)
	{
		rpdl_SCI_GlobalData(12)->TX_End_callback_func();
	}
}

/* End of file */
