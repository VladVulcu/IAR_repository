/*
 * dio_cfg.c
 *
 * Created: 6/5/2015 12:49:03 PM
 *  Author: RacasanV
 */ 
#include "dio_cfg.h"
#include "dio.h"
//#include "enc_cfg.h"
//#include "enc_cfg_opt.h"
#if(ENABLE_INTERRUPT_INT0 == PORT_ENABLE)
/* Routine used for callback in case of INT0 interrupt */
void int0_interrupt_callback(void){
	/* Add user code */
}

#endif

#if(ENABLE_INTERRUPT_INT1 == PORT_ENABLE)

/* Routine used for callback in case of INT0 interrupt */
void int1_interrupt_callback(void){
	/* Add user code */
}

#endif

#if(ENABLE_INTERRUPT_PORTA == PORT_ENABLE)
/* Routine used for callback in case a pin from PCINT[0:7] triggers an interrupt in rising edge */
void pcint0_interrupt_callback_rising_edge(mq_uint8 Pin_u8)
{
      if (Pin_u8 == PIN_1_ENC)
      {
         (void)enc_handler(ENC_1_PHASE_A);
      } 
      if (Pin_u8 == PIN_2_ENC)
      {
	 (void)enc_handler(ENC_1_PHASE_B);
      }	
}
#endif

#if(ENABLE_INTERRUPT_PORTA == PORT_ENABLE)

/* Routine used for callback in case a pin from PCINT[0:7] triggers an interrupt in falling edge */
void pcint0_interrupt_callback_falling_edge(mq_uint8 Pin_u8)
{
      if (Pin_u8 == PIN_1_ENC)
      {
         (void)enc_handler(ENC_1_PHASE_A);
      } 
      if (Pin_u8 == PIN_2_ENC)
      {
	 (void)enc_handler(ENC_1_PHASE_B);
      }	

}

#endif

#if(ENABLE_INTERRUPT_PORTB == PORT_ENABLE)
/* Routine used for callback in case a pin from PCINT[0:7] triggers an interrupt in rising edge */
void pcint1_interrupt_callback_rising_edge(mq_uint8 Pin_u8)
{

}
#endif

#if(ENABLE_INTERRUPT_PORTB == PORT_ENABLE)

/* Routine used for callback in case a pin from PCINT[0:7] triggers an interrupt in falling edge */
void pcint1_interrupt_callback_falling_edge(mq_uint8 Pin_u8)
{
/* Add user code */
}

#endif


#if(ENABLE_INTERRUPT_PORTC == PORT_ENABLE)

	/* Routine used for callback in case a pin from PCINT[8:14] triggers an interrupt in falling edge */
	void pcint2_interrupt_callback_falling_edge(mq_uint8 Pin_u8)
	{
		/* Add user code */
	}

#endif

#if(ENABLE_INTERRUPT_PORTC == PORT_ENABLE)

	/* Routine used for callback in case a pin from PCINT[16:23] triggers an interrupt in rising edge */
	void pcint2_interrupt_callback_rising_edge(mq_uint8 Pin_u8)
	{
		/* Add user code */
	}

#endif

#if(ENABLE_INTERRUPT_PORTD == PORT_ENABLE)

	/* Routine used for callback in case a pin from PCINT[16:23] triggers an interrupt in rising edge */
	void pcint3_interrupt_callback_rising_edge(mq_uint8 Pin_u8)
	{
		/* Add user code */
	}

#endif

#if(ENABLE_INTERRUPT_PORTD == PORT_ENABLE)

	/* Routine used for callback in case a pin from PCINT[16:23] triggers an interrupt in falling edge */
	void pcint3_interrupt_callback_falling_edge(mq_uint8 Pin_u8)
	{
		/* Add user code */
	}

#endif

#if(ENABLE_INTERRUPT_PORTE == PORT_ENABLE)

	/* Routine used for callback in case a pin from PCINT[16:23] triggers an interrupt in rising edge */
	void pcint4_interrupt_callback_rising_edge(mq_uint8 Pin_u8)
	{
		/* Add user code */
	}

#endif

#if(ENABLE_INTERRUPT_PORTE == PORT_ENABLE)

	/* Routine used for callback in case a pin from PCINT[16:23] triggers an interrupt in falling edge */
	void pcint4_interrupt_callback_falling_edge(mq_uint8 Pin_u8)
	{
		/* Add user code */
	}

#endif


#if(ENABLE_INTERRUPT_PORTB == PORT_ENABLE)

	/* Routine used for callback in the case INT0 would fire */
	void pcint0_interrupt_callback(mq_uint8 Pin_u8)
	{
		
	}
	
#endif