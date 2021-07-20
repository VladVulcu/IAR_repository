/*
 * dio.h
 *
 * Created: 6/5/2015 12:48:40 PM
 *  Author: RacasanV
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "App_typedef.h"
//#include "Configuration_options.h"

#define dio_output                     (0x01U)

#define dio_input                       (0x00U)   
   
/* Initial value */
#define PORT_INITIAL_VALUE		           (0x0u)
#define PIN_VALUE_1     (1u)

/*Define for disabling the pull ups */
#define DISABLE_PULLUP                          (0x10u)

/* Define for null operation */
#define PORT_NOP    
#define MQ_NOP
#define MQ_ENABLED (1u)
#define MQ_DISABLED (0u)
#define OPERATION_SUCCESSFUL (1u)
#define ERROR_WITH_PARAMETERS (0u)


/* max number of pins of the portB register  */
#define PORT_MAX_PORTA_REGISTER_PIN	(0x08u)

/* max number of pins of the portB register  */
#define PORT_MAX_PORTB_REGISTER_PIN	(0x08u)

/* max number of pins of the portC register */
#define PORT_MAX_PORTC_REGISTER_PIN	(0x08u)

/* max number of pins of the portD register */
#define PORT_MAX_PORTD_REGISTER_PIN	(0x08u)

/* max number of pins of the portD register */
#define PORT_MAX_PORTE_REGISTER_PIN	(0x08u)

/* Define for enable value */
#define PORT_ENABLE		(0x5Au)

/* Define for disable value */
#define PORT_DISABLE		(0xA5u)


#define PORT_LOW_LEVEL          (0x00u)   

/* Define for logical 1 */
#define PORT_ONE		(0x1u)

/* Define for logical 0 */
#define PORT_ZERO		(0x0u)

/* Define for PORT_A */
#define PORT_A			(0x1u)

/* Define for PORT_B */
#define PORT_B	       	(0x2u)

/* Define for PORT_C */
#define PORT_C			(0x3u)

/* Define for PORT_D */
#define PORT_D			(0x4u)

/* Define for PORT_E */
#define PORT_E			(0x5u)


/* Masks */

/* 0000 0001 - Enable PCIE0 from PCICR */
#define ENABLE_PCIE0					(0x01u)

/* 0001 1110 - Disable PCIE0 from PCICR */
#define DISABLE_PCIE0					(0x1Eu)

/* 0000 0010 - Enable PCIE1 from PCICR */
#define ENABLE_PCIE1					(0x02u)

/* 0001 1101 - Disable PCIE1 from PCICR */
#define DISABLE_PCIE1					(0x1Du)

/* 0000 0100 - Enable PCIE2 from PCICR */
#define ENABLE_PCIE2					(0x04u)

/* 0001 1011 - Disable PCIE2 from PCICR*/
#define DISABLE_PCIE2					(0x1Bu)

/* 0000 1000 - Enable PCIE2 from PCICR */
#define ENABLE_PCIE3					(0x08u)

/* 0001 0111 - Disable PCIE2 from PCICR*/
#define DISABLE_PCIE3					(0x17u)

/* 0001 0000 - Enable PCIE2 from PCICR */
#define ENABLE_PCIE4					(0x10u)

/* 0000 1111 - Disable PCIE2 from PCICR*/
#define DISABLE_PCIE4					(0x0Fu)



/* Define for falling edge interrupt trigger - 0x0000 0010 */
#define INT0_FALLING_EDGE_INTERRUPT				(0x02u)

/* Define for rising edge interrupt trigger  - 0x0000 0011*/
#define INT0_RIZING_EDGE_INTERRUPT				(0x03u)

/* Define for enabling the interrupts for INT0 - 0x000 0001 */
#define INT0_ENABLE_INTERRUPT					(0x01u)	

/* Define for disabling the  interrupt for INT0 - 0x0000 0010 */
#define INT0_DISABLE_INTERRUPT					(0x02u)

/* Define for disabling the interrupt type for INT0  - 0x0000 1100 */
#define INT0_RESET_INTERRUPT_TYPE				(0xC0u)

/* Define for enabling the interrupt for INT1  -0x0000 0010 */
#define INT1_ENABLE_INTERRUPT					(0x02u)

/* Define for enabling the interrupt for INT1 - 0x0000 0001 */
#define INT1_DISABLE_INTRRUPT					(0x01u)

/* Define for enabling the rising edge interrupt for INT1 - 0x000 1000 */
#define INT1_FALLING_EDGE_INTERRUPT				(0x08u)

/* Define for enabling the falling edge interrupt for INT1 - 0x000 1100 */
#define INT1_RISING_EDGE_INTERRUPT				(0x0Cu)

/* Define for reseting all the interrupts  */
#define INT1_RESET_INTERRUPT_TYPE				(0x03u)




/*--------------MACRO - ------------------ */

/* Macro used to set the output on the pin x on PORTB*/
#define PORT_B_OUTPUT(x)	DDRB |= (PORT_ONE << x)

/* Macro used to set the input direction on the pin X on PORTB*/
#define PORT_B_INTPUT(x)	DDRB &= ~(PORT_ONE<<x)

#define PORT_C_OUTPUT(x)	DDRC |= (PORT_ONE << x)

#define PORT_C_INTPUT(x)	DDRC &=~(PORT_ONE<<x)

#define PORT_C_WRITE_ONE(x)     PINC |= (PORT_ONE << x)

#define PORT_C_WRITE_ZERO(x)   PINC &= ~(PORT_ONE << x)

#define PORT_C_TOOGLE(x)	PINC |= (PORT_ONE << x)


#define PORT_D_OUTPUT(x)	DDRD |= (PORT_ONE << x)

#define PORT_D_INTPUT(x)	DDRD &= ~(PORT_ONE<<x)

#define PORT_B_TOOGLE(x)	PINB |= (PORT_ONE << x)

#define PORT_C_TOOGLE(x)	PINC |= (PORT_ONE << x)

#define PORT_D_TOOGLE(x)	PIND |= (PORT_ONE << x)


 

/* enumeration for direction */
enum port_direction {
	/* Define for the input direction */
	port_input = 0x00u,
	
	/* Define for output direction */
	port_output = 0x1u
	};
	
/* enumeration for PullUp/PullDown */
enum port_pullUp {
	
	/* Define for PullDown */
	port_PullDown = 0x0u,
	
	/* Define for PullUp */
	port_PullUp = 0x1u
	};
	
/* enumeration for DIO value */
enum port_value_e{
	
	/* DIO value in case 0V are read from the pin */
	PORT_ZERO_VALUE = 0x0u,
	
	/* DIO value in case 5V are read from the pin */
	PORT_ONE_VALUE = 0x1u
	};

enum port_edge{
	
	/* Define for rising edge */
	PORT_RISING = 0xA5u,
	
	/* Define for falling edge */
	PORT_FALLING = 0x5Au
	
};
	
/* enumeration of the DIO PINs */
enum port_pin
{
	/* Pin 1 */
	PORT_PIN0 = 0x0u,
	
	/* Pin 2 */
	PORT_PIN1 = 0x1u,
	
	/* Pin 3 */
	PORT_PIN2 = 0x2u,
	
	/* Pin 4 */
	PORT_PIN3 = 0x3u,
	
	/* Pin 5 */
	PORT_PIN4 = 0x4u,
	
	/* Pin 6 */
	PORT_PIN5 = 0x5u,
	
	/* Pin 7 */
	PORT_PIN6 = 0x6u,
	
	/* Pin 8 */
	PORT_PIN7 = 0x7u
};

enum port_interrupt_pin
{
	
	PORT_INTERRUPT_PIN0 = 0x01u,
	
	PORT_INTERRUPT_PIN1 = 0x02u,
	
	PORT_INTERRUPT_PIN2 = 0x04u,
	
	PORT_INTERRUPT_PIN3 = 0x08u,
	
	PORT_INTERRUPT_PIN4 = 0x10u,
	
	PORT_INTERRUPT_PIN5 = 0x20u,
	
	PORT_INTERRUPT_PIN6 = 0x40u,
	
	PORT_INTERRUPT_PIN7 = 0x80u
	
};
	
/* Enumeration for DIO interrupt triggers */
enum port_interrupt_e{
	
	/* interrupt generated by change from 5V to 0V */
	FALLING_EDGE = 0x2u,
	
	/* interrupt generated by the change from 0V to 5V */
	RIZING_EDGE = 0x3u
	};
	
/* Enumeration for DIO interrupt pins */
enum pin_interrupt_e{
	
	/* Pins interrupt for PCINT[7:0] */
	PIN_INTERRUPT0 = 0x0u,
	
	/* Pins interrupt for PCINT[14:8] */
	PIN_INTERRUPT1 = 0x1u,
	
	/* Pins interrupt for PCNT[23:16] */
	PIN_INTERRUPT2 = 0x2u
};
	

/* enumeration for PullUp/PullDown */
enum dio_pullUp {
	
	/* Define for PullDown */
	dio_PullDown = 0x0u,
	
	/* Define for PullUp */
	dio_PullUp = 0x1u
	};



extern void dio_disable_pin_edge(enum pin_interrupt_e pin_interrupt_type,enum port_interrupt_pin interrupt_pin, enum port_edge edge_e);

extern void dio_enable_pin_edge(enum pin_interrupt_e pin_interrupt_type,enum port_interrupt_pin interrupt_pin, enum port_edge edge_e);

extern mq_uint8 dio_disable_pin_interrupt(mq_uint8 port_port_u8, mq_uint8 port_pin_u8, mq_uint8 port_edge_u8);

extern mq_uint8 dio_set_data_direction(mq_uint8 port_u8,mq_uint8 pin_u8, mq_uint8 direction_u8);

extern mq_uint8 dio_write_digital(mq_uint8 Port_u8, mq_uint8 Pin_u8, mq_uint8 Level_u8 );

extern void dio_interrupt_PORTA_handling(void);

extern void dio_init(void);


/**
	\fn				void dio_set_PullUp(dio_uint8_t Port, dio_uint8_t Pin, enum dio_pullUp dio_pullUpValue)
	\brief			enable or disable the pullUp resistor for the selected pin 
	\param [in]		Port : variable used to select on which Port to set the Pin. Possible values : PORT_B, PORT_C,PORT_D.
	\param [in]		Pin  : enumeration for the use of a certain pin. Possible values : DIO_PIN0, DIO_PIN1, DIO_PIN2 , DIO_PIN3 , DIO_PIN4,DIO_PIN5, DIO_PIN6,DIO_PIN7.
	\param [in]		dio_pullUpValue : enumeration used for selecting if the pin has the pullUp enabled or nor. Possible values :  dio_PullDown and  dio_PullUp 
	\return			None
	\details		Routine used to enable or disable the PullUp resistor for the selected pin in the selected PORT
	\history		05.06.2015 : Racasan Vlad - creation	
*/
extern void dio_set_PullUp(mq_uint8 Port, mq_uint8 Pin, enum dio_pullUp dio_pullUpValue);


/**
	\fn				enum dio_value_e dio_read_digital(uint8_t Port, uint8_t Pin)
	\brief			Routine used to read the values from a specific pin
	\param [in]		Port : variable used to select on which Port to set the Pin. Possible values : PORT_B, PORT_C,PORT_D
	\param [in]		Pin  : enumeration for the use of a certain pin. Possible values : DIO_PIN0, DIO_PIN1, DIO_PIN2 , DIO_PIN3 , DIO_PIN4,DIO_PIN5, DIO_PIN6,DIO_PIN7
	\return			dio_value_e : enumeration that can give back the following values : DIO_ZERO_VALUE in case it is a Logical 0 on the pin and DIO_ONE_VALUE in case the value is a logical 1
	\details		Routine used to read the values from a specific pin
	\history		05.06.2015 : Racasan Vlad - creation
*/
extern mq_uint8 dio_read_digital(mq_uint8 Port_u8, mq_uint8 Pin_u8);

/**
	\fn				void dio_toggle_pin (dio_uint8_t Port, dio_uint8_t Pin)
	\brief			Routine used to switch between the logical 1 and logical 0 values on the selected PIN
	\param [in]		Port : variable used to select on which Port to set the Pin. Possible values : PORT_B, PORT_C,PORT_D
	\param [in]		Pin : enumeration for the use of a certain pin. Possible values : DIO_PIN0, DIO_PIN1, DIO_PIN2 , DIO_PIN3 , DIO_PIN4,DIO_PIN5, DIO_PIN6,DIO_PIN7
	\return			None
	\details		Routine used to switch between the logical 1 and logical 0 values on the selected PIN
	\history		05.06.2015 : Racasan Vlad - creation

*/
extern void dio_toggle_pin(mq_uint8 Port, mq_uint8 Pin);




/*-------------------------=========================-------------------------------- */
/*-----------------------------------DIO DRV--------------------------------------- */
/*-------------------------=========================-------------------------------- */

/* Initial setup for PORTA by setting the direction as output - 0x1111 1111 */
#define PORTA_MASK_INITIALIZATION	(0xFFu)

/* Initial setup for PORTB by setting the direction as output - 0x1111 1111 */
#define PORTB_MASK_INITIALIZATION	(0xFFu)

/* Initial setup for PORTC by setting the direction as output - 0x0111 1111 */
#define PORTC_MASK_INITIALIZATION	(0x7Fu)

/* Initial setup for PORTD by setting the direction as output - 0x1111 1111 */
#define PORTD_MASK_INITIALIZATION	(0xFFu)

/* Initial setup for PORTE by setting the direction as output - 0x0000 1111 */
#define PORTE_MASK_INITIALIZATION	(0x0Fu)

/* Define for rising edge */
#define PORT_RISING_EDGE		(0x0u)

/*Define for falling edge */
#define PORT_FALLING_EDGE	        (0x1u)

#define PORT_BOTH_EDGES		        (0x2u)

/* Initial value */
#define PORT_INITIAL_VALUE		(0x0u)


extern mq_uint8 dio_enable_pin_interrupt(mq_uint8 port_port_u8,mq_uint8 port_pin_u8, mq_uint8 port_edge_u8);





#endif /* DIO_H_ */
