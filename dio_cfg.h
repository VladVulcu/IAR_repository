/*
 * dio_cfg.h
 *
 * Created: 6/5/2015 12:48:51 PM
 *  Author: RacasanV
 */ 



#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "dio.h"

/* Define for  */
#define ENABLE_INTERRUPT_INT0		PORT_ENABLE

#define ENABLE_INTERRUPT_INT1		PORT_ENABLE

#define ENABLE_INTERRUPT_PORTA          PORT_ENABLE

#define ENABLE_INTERRUPT_PORTB		PORT_ENABLE

#define ENABLE_INTERRUPT_PORTC		PORT_ENABLE

#define ENABLE_INTERRUPT_PORTD		PORT_ENABLE

#define ENABLE_INTERRUPT_PORTE		PORT_ENABLE

#define ENABLE_PIN_EDGE			PORT_ENABLE


#define ENABLE_TOOGLE_PIN		PORT_ENABLE

#define ENABLE_READ_PIN			PORT_ENABLE

#define ENABLE_WRITE_PIN		PORT_ENABLE

#define ENABLE_SET_PULLUP		PORT_ENABLE

#define ENABLE_GET_DATA_DIRECTION	PORT_ENABLE

#define ENABLE_SET_DATA_DIRECTION	PORT_ENABLE


#define EDGE_INTERRUPT0_ENABLE	PORT_ENABLE

/* eu */
#define PIN_1_ENC PORT_ENABLE

#define PIN_2_ENC PORT_ENABLE

#define ENC_1_PHASE_A PORT_ENABLE

#define ENC_1_PHASE_B PORT_ENABLE


/* Routines for interrupt callback */
/**
	\fn		int0_interrupt_callback(void)
	\brief		callback from the INT0 interrupt
	\param[in]	none
	\return		none

*/
extern void int0_interrupt_callback();

/**
	\fn		int1_interrupt_callback(void)
	\brief		callback from the INT1 interrupt
	\param[in]	none
	\return		none
*/
extern void int1_interrupt_callback(void);

/**
	\fn		pcint0_interrupt_callback_rising_edge(uint8_t Pin_u8)
	\brief		callback from the PCINT0 interrupt in rising edge
	\param[in]	Pin_u8  :  the number of the Pin that generates the interrupt
	\return		none
*/
extern void pcint0_interrupt_callback_rising_edge(mq_uint8 Pin_u8);

/** 
	\fn		pcint0_interrupt_callback_falling_edge(uint8_t Pin_u8)
	\brief		callback from the PCINT0 interrupt in falling edge
	\param[in]	Pin_u8 : the number of the Pin that generates the interrupt
	\return		none

*/
extern void pcint0_interrupt_callback_falling_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint1_interrupt_callback_rising_edge(uint8_t Pin_u8)
	\brief		callback from the PCINT1 interrupt in rising edge
	\param[in]	Pin_u8 : the number of the Pin that generates the interrupt
	\return		none
*/
extern void pcint1_interrupt_callback_rising_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint1_interrupt_callback_rising_edge(uint8_t Pin_u8)
	\brief		callback from the PCINT1 interrupt in falling edge
	\param[in]	Pin_u8 : the number of the Pin that generates the interrupt
	\return		none
*/
extern void pcint1_interrupt_callback_falling_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint2_interrupt_callback_rising_edge(uint_t Pin_u8)
	\brief		callback from the PCINT2 interrupt in rising edge
	\param[in]	Pin_u8 : the number of the Pin that generates the interrupt
	\return		none
*/
extern void pcint2_interrupt_callback_rising_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint2_interrupt_callback_falling_edge(uint8_t	Pin_u8)
	\brief		callback from the PCINT2 interrupt in falling edge
	\param[in]	Pin_u8 : the number of the pin that generates the interrupt
	\return		none
*/
extern void pcint2_interrupt_callback_falling_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint2_interrupt_callback_rising_edge(uint_t Pin_u8)
	\brief		callback from the PCINT2 interrupt in rising edge
	\param[in]	Pin_u8 : the number of the Pin that generates the interrupt
	\return		none
*/
extern void pcint3_interrupt_callback_rising_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint2_interrupt_callback_falling_edge(uint8_t	Pin_u8)
	\brief		callback from the PCINT2 interrupt in falling edge
	\param[in]	Pin_u8 : the number of the pin that generates the interrupt
	\return		none
*/
extern void pcint3_interrupt_callback_falling_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint2_interrupt_callback_rising_edge(uint_t Pin_u8)
	\brief		callback from the PCINT2 interrupt in rising edge
	\param[in]	Pin_u8 : the number of the Pin that generates the interrupt
	\return		none
*/
extern void pcint4_interrupt_callback_rising_edge(mq_uint8 Pin_u8);

/**
	\fn		pcint2_interrupt_callback_falling_edge(uint8_t	Pin_u8)
	\brief		callback from the PCINT2 interrupt in falling edge
	\param[in]	Pin_u8 : the number of the pin that generates the interrupt
	\return		none
*/
extern void pcint4_interrupt_callback_falling_edge(mq_uint8 Pin_u8);


extern void pcint0_interrupt_calback(mq_uint8 Pin_u8);

#endif /* DIO_CFG_H_ */