


/*
 * dio.c
 *
 * Created: 6/5/2015 12:48:30 PM
 *  Author: RacasanV
 */ 

  #include "App_typedef.h"
  #include "iom324pb.h"
  //#include "inavr.h"
  //#include "ina90.h"
  #include "dio.h"
  #include "dio_cfg.h"

mq_uint8 interrupt_flag_u8;

/* Verify if the interrupt is enabled for portB */
#if( ENABLE_INTERRUPT_PORTA == PORT_ENABLE)
	
  /* Global variable used for identifying the interrupt from PORTB */
  mq_uint8 PCMSK0_data_old_u8 = PORT_INITIAL_VALUE;

#endif


/* Verify if the interrupt is enabled for portB */
#if( ENABLE_INTERRUPT_PORTB == PORT_ENABLE)
	
  /* Global variable used for identifying the interrupt from PORTB */
  mq_uint8 PCMSK1_data_old_u8 = PORT_INITIAL_VALUE;

#endif

/* Verify if the interrupt is enabled for PORTC */
#if (ENABLE_INTERRUPT_PORTC == PORT_ENABLE)

  /* Global variable used for identifying the interrupt from PORTC */
  mq_uint8 PCMSK2_data_old_u8 = PORT_INITIAL_VALUE;
	
#endif
  
 /* Verify if the interrupt is enabled for PORTC */
#if (ENABLE_INTERRUPT_PORTD == PORT_ENABLE)

  /* Global variable used for identifying the interrupt from PORTC */
  mq_uint8 PCMSK3_data_old_u8 = PORT_INITIAL_VALUE;
	
#endif
  
 /* Verify if the interrupt is enabled for PORTC */
#if (ENABLE_INTERRUPT_PORTE == PORT_ENABLE)

  /* Global variable used for identifying the interrupt from PORTC */
  mq_uint8 PCMSK4_data_old_u8 = PORT_INITIAL_VALUE;
	
#endif

  /* verify if the interrupt is enabled for PORTB */
#if( ENABLE_INTERRUPT_PORTA == PORT_ENABLE)

  /* Global variable used for keeping records of enabling or disabling the rising edge interrupt  */
  mq_uint8 interrupt_pc0_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabling or disabling the falling edge interrupt  */
  mq_uint8 interrupt_pc0_falling = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabled/disabled the edge interrupts */
  mq_uint8 interrupt_PORTA_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabled/disabled the edge interrupts */
  mq_uint8 interrupt_PORTA_falling = PORT_INITIAL_VALUE;

#endif
  
/* verify if the interrupt is enabled for PORTB */
#if( ENABLE_INTERRUPT_PORTB == PORT_ENABLE)

  /* Global variable used for keeping records of enabling or disabling the rising edge interrupt  */
  mq_uint8 interrupt_pc1_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabling or disabling the falling edge interrupt  */
  mq_uint8 interrupt_pc1_falling = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabled/disabled the edge interrupts */
  mq_uint8 interrupt_PORTB_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabled/disabled the edge interrupts */
  mq_uint8 interrupt_PORTB_falling = PORT_INITIAL_VALUE;

#endif

/* Verify if the interrupt is enabled for PORTC */
#if (ENABLE_INTERRUPT_PORTC == PORT_ENABLE)

  /* Global variable used for keeping  records of enabling or disabling the rising edge interrupt */
  mq_uint8 interrupt_pc2_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_pc2_falling = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabled/disabled the edge interrupts */
  mq_uint8 interrupt_PORTC_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabled/disabled the edge interrupts */
  mq_uint8 interrupt_PORTC_falling = PORT_INITIAL_VALUE;
	
#endif

/* Verify of the interrupt is enabled for PORTD */
#if (ENABLE_INTERRUPT_PORTD == PORT_ENABLE)

  /* Global variable used for keeping records of enabling or disabling the rising edge interrupt */
  mq_uint8 interrupt_pc3_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_pc3_falling = PORT_INITIAL_VALUE;
  
   /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_PORTD_rising = PORT_INITIAL_VALUE;
    
   /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_PORTD_falling = PORT_INITIAL_VALUE;
	
#endif
  
 /* Verify of the interrupt is enabled for PORTD */
#if (ENABLE_INTERRUPT_PORTE == PORT_ENABLE)

  /* Global variable used for keeping records of enabling or disabling the rising edge interrupt */
  mq_uint8 interrupt_pc4_rising = PORT_INITIAL_VALUE;
  
  /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_pc4_falling = PORT_INITIAL_VALUE;
  
   /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_PORTE_rising = PORT_INITIAL_VALUE;
    
   /* Global variable used for keeping records of enabling or disabling the falling edge interrupt */
  mq_uint8 interrupt_PORTE_falling = PORT_INITIAL_VALUE;
	
#endif

 
  
  
/* Initialization routine for all the pins  */
/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-48, SD_DIO_Drv-55, SD_DIO_Drv-70, SD_DIO_Drv-57, SD_DIO_Drv-62, SD_DIO_Drv-67,                      */
/* --------------------------------------------------                                                             */
void dio_init(void)
{
  /* Set all the values from PORTB as output low */
  DDRA |= PORTA_MASK_INITIALIZATION;
  
  /* Set all the values from PORTB as output low */
  DDRB |= PORTB_MASK_INITIALIZATION;
          
  /* Set all the values from PORTC as output low */
  DDRC |= PORTC_MASK_INITIALIZATION;
  
  /* Set all the values from PORTD as output low */
  DDRD |= PORTD_MASK_INITIALIZATION;
  
  /*Set all the values form PORTE as output low */
  DDRE |= PORTE_MASK_INITIALIZATION;
  
  /* Disable the pull ups for every pin */
  MCUCR |= DISABLE_PULLUP;
  
  interrupt_flag_u8=MQ_DISABLED;
}


/* Routine used to enable a pin interrupt on a specific edge */
/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-316, SD_DIO_Drv-321, SD_DIO_Drv-322, SD_DIO_Drv-323, SD_DIO_Drv-325, SD_DIO_Drv-326, SD_DIO_Drv-327,*/
/* SD_DIO_Drv-333, SD_DIO_Drv-335, SD_DIO_Drv-338, SD_DIO_Drv-340                                                 */
/* --------------------------------------------------                                                             */
mq_uint8 dio_enable_pin_interrupt(mq_uint8 port_port_u8,mq_uint8 port_pin_u8, mq_uint8 port_edge_u8)
{
  /* Local variable used to store the opearation status */
  mq_uint8 ReturnValue; 
    /*Local variable used to store the location of th pin   */
  mq_uint8 PinSpot_u8;
  
  ReturnValue= OPERATION_SUCCESSFUL;
  PinSpot_u8 = PORT_INITIAL_VALUE;


  /* Set the Pin location */
  PinSpot_u8 |= PIN_VALUE_1<<port_pin_u8;

  /* switch between the ports */
  switch (port_port_u8)
  {
    /* Case for port B */
    case PORT_A:
    {
      /* Enable the PCIE0 interrupt */
      PCICR |= ENABLE_PCIE0;
		
      /* enable the interrupt on the desired pin */
      PCMSK0 |= PinSpot_u8;
			
      /* Switch between the edges on which the interrupt to be enabled */
      switch(port_edge_u8)
      {
        /*  Case for rising edge*/
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTA_rising |= PinSpot_u8;
	      }
	      /* Break case */
        break;
	
        /* Case for falling edge */
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */
          interrupt_PORTA_falling |= PinSpot_u8;
        }
	      /* Break case */
        break;
	
        /* Case for both edges */
        case PORT_BOTH_EDGES:
        {
          /* Set in the global rising flag the new state */
          interrupt_PORTA_rising |= PinSpot_u8;
          
          /* Set in the global falling flag the new state */
          interrupt_PORTA_falling |= PinSpot_u8;
        }
        /* Break case */
	      break;
				
        default:
        {	
          /* Set return value as error */
          ReturnValue = ERROR_WITH_PARAMETERS;
        }
        /* Break case */
        break;
      }
    }
    /*  Break case for port B*/
    break;
    
    /* Case for port B */
    case PORT_B:
    {
      /* Enable the PCIE0 interrupt */
      PCICR |= ENABLE_PCIE1;
		
      /* enable the interrupt on the desired pin */
      PCMSK0 |= PinSpot_u8;
			
      /* Switch between the edges on which the interrupt to be enabled */
      switch(port_edge_u8)
      {
        /*  Case for rising edge*/
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTB_rising |= PinSpot_u8;
        }
        /* Break case */
        break;
	
        /* Case for falling edge */
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */
          interrupt_PORTB_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
	
        /* Case for both edges */
        case PORT_BOTH_EDGES:
        {
          /* Set in the global rising flag the new state */
          interrupt_PORTB_rising |= PinSpot_u8;
          
          /* Set in the global falling flag the new state */
          interrupt_PORTB_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
				
        default:
        {	
          /* Set return value as error */
          ReturnValue = ERROR_WITH_PARAMETERS;
        }
        /* Break case */
        break;
      }
    }
    /*  Break case for port B*/
    break;
		
    case PORT_C:
    {

      /* Enable the PCIE1 interrupt */
      PCICR |= ENABLE_PCIE2;
		
      /* enable the interrupt on the desired pin */
      PCMSK2 |= PinSpot_u8;
	
      /* Switch between the edges */
	    switch(port_edge_u8)
      {
        /* Case for rising edge */
        case PORT_RISING_EDGE:
        {
          /* set the global rising edge interrupt */
          interrupt_PORTC_rising |= PinSpot_u8;
        }
        /* Break case */
        break;
	
        /* Case for falling edge */
        case PORT_FALLING_EDGE:
        {
          /* Set the global falling edge interrupt*/
          interrupt_PORTC_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
          
        /* Case for both edges */
        case PORT_BOTH_EDGES:
        {
          /* Set the global rising edge interrupt */
          interrupt_PORTC_rising |= PinSpot_u8;
            
          /* Set the global falling edge interrupt */
          interrupt_PORTC_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
	
        /* Default case */
        default:
        {
          /* Set return value as error */
          ReturnValue = ERROR_WITH_PARAMETERS;
        }
        
        /* Break case  */
        break;
      }
    }
    /* Break case */
    break;
	
    /* case for PORT D */
    case PORT_D:
    {
      /* Enable the PCIE3 interrupt */
	    PCICR |= ENABLE_PCIE3;
			
      /* enable the interrupt on the desired pin */
      PCMSK3 |= PinSpot_u8;
	
      /* switch between the edges */
      switch(port_edge_u8)
      {
        /* case for rising edge */ 
        case PORT_RISING_EDGE:
        {
          /* enable the global interrupt on the rising edge */
          interrupt_PORTD_rising |= PinSpot_u8;
	
         /* Break case */
        }
        break;
	 
        /* case for falling edge */
        case PORT_FALLING_EDGE:
        {
           /* enable the global falling edge interrupt */
           interrupt_PORTD_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
	
        /* case for both edges */
        case PORT_BOTH_EDGES:
        {
          /* Enable the global rising edge interrupt */
	        interrupt_PORTD_rising |= PinSpot_u8;
          
          /* Enable the global falling edge interrupt */
          interrupt_PORTD_falling |= PinSpot_u8;
	      }
	      /* Break case */
        break;
	
        /* Default case */
	      default:
	      {
          /* Set return value as error */
          ReturnValue = ERROR_WITH_PARAMETERS;
	      }
        /* Break case */
         break;
      }
    }
    /* Break case */
    break;


    /* case for PORT D */
    case PORT_E:
    {
      /* Enable the PCIE3 interrupt */
      PCICR |= ENABLE_PCIE4;
      
      /* enable the interrupt on the desired pin */
      PCMSK4 |= PinSpot_u8;
  
      /* switch between the edges */
      switch(port_edge_u8)
      {
        /* case for rising edge */ 
        case PORT_RISING_EDGE:
        {
          /* enable the global interrupt on the rising edge */
          interrupt_PORTE_rising |= PinSpot_u8;
  
         /* Break case */
        }
        break;
   
        /* case for falling edge */
        case PORT_FALLING_EDGE:
        {
           /* enable the global falling edge interrupt */
           interrupt_PORTE_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
  
        /* case for both edges */
        case PORT_BOTH_EDGES:
        {
          /* Enable the global rising edge interrupt */
          interrupt_PORTE_rising |= PinSpot_u8;
          
          /* Enable the global falling edge interrupt */
          interrupt_PORTE_falling |= PinSpot_u8;
        }
        /* Break case */
        break;
  
        /* Default case */
        default:
        {
          /* Set return value as error */
          ReturnValue = ERROR_WITH_PARAMETERS;
        }
        /* Break case */
         break;
      }
    }
    /* Break case */
    break;	
	
    /* Default case */
    default:
    {
      /* Set return value as error */
      ReturnValue = ERROR_WITH_PARAMETERS;	
    }
    /* Break case */
    break;
  }
  /* Return the status of the operation */
  return ReturnValue;
}

/* Routine used to disable a pin interrupt on a specific edge */
/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-345, SD_DIO_Drv-350, SD_DIO_Drv-351, SD_DIO_Drv-352, SD_DIO_Drv-354, SD_DIO_Drv-355, SD_DIO_Drv-356,*/
/* SD_DIO_Drv-358, SD_DIO_Drv-360, SD_DIO_Drv-363, SD_DIO_Drv-365                                                 */
/* --------------------------------------------------                                                             */
mq_uint8 dio_disable_pin_interrupt(mq_uint8 port_port_u8, mq_uint8 port_pin_u8, mq_uint8 port_edge_u8)
{
  mq_uint8 ReturnValue_u8;
  mq_uint8 PinCount_u8;

  ReturnValue_u8 = OPERATION_SUCCESSFUL;
  /* Set the pin location */
  PinCount_u8 = PIN_VALUE_1<<port_pin_u8;
  
  /* Create the oposite mask */
  PinCount_u8 = ~PinCount_u8;
  
  switch (port_port_u8)
  {

    case PORT_A:
    {
      /* Switch between the edges */
      switch(port_edge_u8)
      {
        /* Case for rising edge */
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTA_rising &= PinCount_u8;
        }  
        /* Break case */
        break;
        
        /* Case for falling edge */
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */  
            interrupt_PORTA_falling &= PinCount_u8;
        } 
        /* Break case */
        break;
        
        case PORT_BOTH_EDGES:
        {
            /* Set in the global flag the new state */  
            interrupt_PORTA_rising &= PinCount_u8;
            
            /* Set in the global flag the new state */  
            interrupt_PORTA_rising &= PinCount_u8;
            
            /* disable the interrupt on the desired pin */
            PCMSK0 &= PinCount_u8;

        }  
        /* Break case */
        break;
        
        /* Default case */
        default :
        {
         /* Set return value as error */
         ReturnValue_u8 = ERROR_WITH_PARAMETERS;          
        }
        break;
      }
   }
   /* Break case */
   break;

  /* Case for pin in the port B section */
  case PORT_B:
    {
      switch(port_edge_u8)
      {
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTB_rising &= PinCount_u8;
        }  
        /* Break case */
        break;
        
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */  
            interrupt_PORTB_falling &= PinCount_u8;
        } 
        /* Break case */
        break;
        
        case PORT_BOTH_EDGES:
           
           /* Set in the global flag the new state */  
            interrupt_PORTB_rising &= PinCount_u8;
            
            /* Set in the global flag the new state */  
            interrupt_PORTB_rising &= PinCount_u8;
            
            /* disable the interrupt on the desired pin */
            PCMSK1 &= PinCount_u8;
           
        /* Break case */
        break;
        
        /* Default case */
        default :
        {
         /* Set return value as error */
         ReturnValue_u8 = ERROR_WITH_PARAMETERS;          
        }
        break;
      }
   }
   /* Break case */
   break;
    
  case PORT_C:
    {
      switch(port_edge_u8)
      {
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTC_rising &= PinCount_u8;
        }  
        /* Break case */
        break;
        
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */  
            interrupt_PORTC_falling &= PinCount_u8;
        } 
        /* Break case */
        break;
        
        case PORT_BOTH_EDGES:
           
           /* Set in the global flag the new state */  
            interrupt_PORTC_rising &= PinCount_u8;
            
            /* Set in the global flag the new state */  
            interrupt_PORTC_falling &= PinCount_u8;
            
            /* disable the interrupt on the desired pin */
            PCMSK2 &= PinCount_u8;
           
        /* Break case */
        break;
        
        /* Default case */
        default :
        {
         /* Set return value as error */
         ReturnValue_u8 = ERROR_WITH_PARAMETERS;          
        }
        break;
      }
   }
    /* Break case */
    break;
    
  case PORT_D:
  {
      switch(port_edge_u8)
      {
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTD_rising &= PinCount_u8;
        }  
        /* Break case */
        break;
        
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */  
            interrupt_PORTD_falling &= PinCount_u8;
        } 
        /* Break case */
        break;
        
        case PORT_BOTH_EDGES:
           
           /* Set in the global flag the new state */  
            interrupt_PORTD_rising &= PinCount_u8;
            
            /* Set in the global flag the new state */  
            interrupt_PORTD_falling &= PinCount_u8;
            
            /* disable the interrupt on the desired pin */
            PCMSK3 &= PinCount_u8;
           
        /* Break case */
        break;
        
        /* Default case */
        default :
        {
         /* Set return value as error */
         ReturnValue_u8 = ERROR_WITH_PARAMETERS;          
        }
        break;
      }
  }
  /* Break case */
  break;

  case PORT_E:
  {
      switch(port_edge_u8)
      {
        case PORT_RISING_EDGE:
        {
          /* Set in the global flag the new state */  
          interrupt_PORTE_rising &= PinCount_u8;
        }  
        /* Break case */
        break;
        
        case PORT_FALLING_EDGE:
        {
          /* Set in the global flag the new state */  
            interrupt_PORTE_falling &= PinCount_u8;
        } 
        /* Break case */
        break;
        
        case PORT_BOTH_EDGES:
           
           /* Set in the global flag the new state */  
            interrupt_PORTE_rising &= PinCount_u8;
            
            /* Set in the global flag the new state */  
            interrupt_PORTE_falling &= PinCount_u8;
            
            /* disable the interrupt on the desired pin */
            PCMSK4 &= PinCount_u8;
           
        /* Break case */
        break;
        
        /* Default case */
        default :
        {
         /* Set return value as error */
         ReturnValue_u8 = ERROR_WITH_PARAMETERS;          
        }
        break;
      }
  }
  /* Break case */
  break;
  
  /* Default case*/  
  default : 
  {
    /* Set return value as error */
    ReturnValue_u8 = ERROR_WITH_PARAMETERS;  
  }
  break;
  
  }
  return ReturnValue_u8;
}


/* Set pull up resistor  */
/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-431, SD_DIO_Drv-436, SD_DIO_Drv-437, SD_DIO_Drv-438, SD_DIO_Drv-440, SD_DIO_Drv-441, SD_DIO_Drv-442,*/
/* SD_DIO_Drv-444, SD_DIO_Drv-445, SD_DIO_Drv-446, SD_DIO_Drv-448, SD_DIO_Drv-450, SD_DIO_Drv-453, SD_DIO_Drv-455 */
/* --------------------------------------------------                                                             */
void dio_set_PullUp(mq_uint8 Port, mq_uint8 Pin, enum dio_pullUp dio_pullUpValue){
	
	/* Switch between the ports */
	switch (Port)
	{
          /* Case for PORTA */
		case PORT_A :
		{
			/* verify if the desired state is to activate the pullUp */
			if(dio_pullUpValue == dio_PullUp)
			{
				/* Enable the Pull Up */
				PORTA |= dio_PullUp << Pin;
				
			}
			else
			{
				/* Disable the Pull Up */
				PORTA &= dio_PullDown << Pin;
				
			}
			break;
		}
		
          
		/* Case for PORTB */
		case PORT_B :
		{
			/* verify if the desired state is to activate the pullUp */
			if(dio_pullUpValue == dio_PullUp)
			{
				/* Enable the Pull Up */
				PORTB |= dio_PullUp << Pin;
				
			}
			else
			{
				/* Disable the Pull Up */
				PORTB &= dio_PullDown << Pin;
				
			}
			break;
		}
		
		/* Case fir PORTC */
		case PORT_C :
		{
			/* verify if the desired state is to activate the pullUp state */
			if(dio_pullUpValue == dio_PullUp)
			{
				/* Enable the Pull Up */
				PORTC |= dio_PullUp << Pin;
				
			}
			else
			{
				/* Disable the Pull Up */
				PORTC &= dio_PullDown << Pin;
				
			}
			break;
		}
		
		/* Case for PORTD */
		case PORT_D :
		{
			/* Verify if the desired state is to activate the pullUp state */
			if(dio_pullUpValue == dio_PullUp)
			{
				/* Enable the Pull Up */
				PORTD |= dio_PullUp << Pin;
				
			}
			else
			{
				/* Disable the Pull Up */
				PORTD &= dio_PullDown << Pin;
				
			}
			break;
		}
		
		/* default case */
		default:
		{
			/* Do nothing */
			MQ_NOP;
			break;
		}
	}
}

/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-258, SD_DIO_Drv-263, SD_DIO_Drv-264, SD_DIO_Drv-278, SD_DIO_Drv-279, SD_DIO_Drv-280,                */
/* SD_DIO_Drv-282, SD_DIO_Drv-283, SD_DIO_Drv-284, SD_DIO_Drv-267, SD_DIO_Drv-269, SD_DIO_Drv-272, SD_DIO_Drv-274 */
/* --------------------------------------------------                                                             */
void dio_enable_pin_edge(enum pin_interrupt_e pin_interrupt_type,enum port_interrupt_pin interrupt_pin, enum port_edge edge_e)
{

	
			if(edge_e == RIZING_EDGE)
			{
				interrupt_PORTA_rising |= interrupt_pin;
			}
			else
			{
				interrupt_PORTA_falling |= interrupt_pin;
				if(interrupt_pin == PORT_INTERRUPT_PIN4)
				{
					dio_set_PullUp(PORTA,PORT_PIN4,dio_PullUp);
				}
				else
				{
					dio_set_PullUp(PORTA,PORT_PIN5,dio_PullUp);
				}
			}

	



	
};

/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-287, SD_DIO_Drv-292, SD_DIO_Drv-293, SD_DIO_Drv-294, SD_DIO_Drv-296, SD_DIO_Drv-297, SD_DIO_Drv-311,*/
/* SD_DIO_Drv-298, SD_DIO_Drv-300, SD_DIO_Drv-301, SD_DIO_Drv-302, SD_DIO_Drv-304, SD_DIO_Drv-306, SD_DIO_Drv-309 */
/* --------------------------------------------------                                                             */
void dio_disable_pin_edge(enum pin_interrupt_e pin_interrupt_type,enum port_interrupt_pin interrupt_pin, enum port_edge edge_e)
{
	
				if(edge_e == RIZING_EDGE)
				{
					interrupt_PORTA_rising &= ~interrupt_pin;
				}
				else
				{
					interrupt_PORTA_falling &= ~interrupt_pin;
					
					if(interrupt_pin == PORT_INTERRUPT_PIN4)
					{
						dio_set_PullUp(PORTA,PORT_PIN4,dio_PullDown);
					}
					else
					{
						dio_set_PullUp(PORTA,PORT_PIN5,dio_PullDown);
					}
					
				}
				
			
	
};





/* Routine used to set the data direction for a specific pin */
/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-370, SD_DIO_Drv-375, SD_DIO_Drv-376, SD_DIO_Drv-377, SD_DIO_Drv-379, SD_DIO_Drv-380, SD_DIO_Drv-381,*/
/* SD_DIO_Drv-383, SD_DIO_Drv-384, SD_DIO_Drv-385, SD_DIO_Drv-387, SD_DIO_Drv-389, SD_DIO_Drv-392, SD_DIO_Drv-394 */
/* --------------------------------------------------                                                             */
mq_uint8 dio_set_data_direction(mq_uint8 port_u8,mq_uint8 pin_u8, mq_uint8 direction_u8)
{
  mq_uint8 ReturnValue_u8;
  mq_uint8 port_mask_u8;

  port_mask_u8 = PORT_ZERO;

  ReturnValue_u8 = OPERATION_SUCCESSFUL;

  switch(port_u8)
  {
    case PORT_A:
    {
      switch (direction_u8)
      {
        /* Case for the output direction */
        case dio_output:
        {
          port_mask_u8 = (PORT_ONE << pin_u8);
            
          DDRA |= port_mask_u8;
              
        }
        /* Break case */
        break;
          
        /* Case for the input direction */
        case dio_input:
        {
       
          port_mask_u8 = (~(PORT_ONE<< pin_u8));
          
          /* Set the direction as output */
          DDRA &= port_mask_u8;
        }
        /* Break case */
        break;

        /* Default case */
        default :
        {
          ReturnValue_u8 = ERROR_WITH_PARAMETERS;
        }
        /* Break case */
        break;
      }
    } 
    /* Break case */
    break;
    
    case PORT_B:
    {
      switch (direction_u8)
      {
        /* Case for the output direction */
        case dio_output:
        {
          port_mask_u8 = (PORT_ONE << pin_u8);
        
          DDRB |= port_mask_u8;
        }
        
        /* Break case */
        break;
      
        /* Case for the input direction */
        case dio_input:
        {
        
          port_mask_u8 = (~(PORT_ONE<< pin_u8));
      
          /* Set the direction as output */
          DDRB &= port_mask_u8;
        }
        
        /* Break case */
        break;
      
        /* Default case */
        default :
        {
          ReturnValue_u8 = ERROR_WITH_PARAMETERS;
        }
        /* Break case */
        break;
      }
    } 
    /* Break case */
    break;
  
    case PORT_C:
  {
   switch (direction_u8)
    {
      /* Case for the output direction */
      case dio_output:
      {
        DDRC |= (PORT_ONE << pin_u8);
      }
      /* Break case */
      break;
      
      /* Case for the input direction */
      case dio_input:
      {
        DDRC &= (PORT_ZERO << pin_u8);
      }
      /* Break case */
      break;
      
      /* Default case */
      default :
      {
       ReturnValue_u8 = ERROR_WITH_PARAMETERS;
      }
      /* Break case */
      break;
    } 
  }
  /* Break case */
  break;

    case PORT_D:
  {
     switch (direction_u8)
    {
      /* Case for the output direction */
      case dio_output:
      {
        DDRD |= (PORT_ONE << pin_u8);
      }
      /* Break case */
      break;
      
      /* Case for the input direction */
      case dio_input:
      {
        DDRD &= (PORT_ZERO << pin_u8);
      }
      /* Break case */
      break;
      
      /* Default case */
      default :
      {
       ReturnValue_u8 = ERROR_WITH_PARAMETERS;
      }
      /* Break case */
      break;
    }
  } 

        case PORT_E:
    {
      switch (direction_u8)
      {
      /* Case for the output direction */
      case dio_output:
      {
        DDRE |= (PORT_ONE << pin_u8);
      }
      /* Break case */
      break;
      
      /* Case for the input direction */
      case dio_input:
      {
        DDRE &= (PORT_ZERO << pin_u8);
      }
      /* Break case */
      break;
      
      /* Default case */
      default :
      {
       ReturnValue_u8 = ERROR_WITH_PARAMETERS;
      }
      /* Break case */
      break;
    } 

  }

  
    /* Default case */
    default :
    { 
      /* set the return value as error with paramters */
      ReturnValue_u8 = ERROR_WITH_PARAMETERS;
    }
    
    /*Break case */
    break;
  }

  return  ReturnValue_u8;
}

/*Routine used to read the digital value */
/* SW Design DOORS attribute :                                                                                    */
/*                                                                                                                */
/* SD_DIO_Drv-518, SD_DIO_Drv-523, SD_DIO_Drv-524, SD_DIO_Drv-525, SD_DIO_Drv-527, SD_DIO_Drv-528, SD_DIO_Drv-529,*/
/* SD_DIO_Drv-535, SD_DIO_Drv-545, SD_DIO_Drv-546, SD_DIO_Drv-547, SD_DIO_Drv-540, SD_DIO_Drv-542                 */
/* --------------------------------------------------                                                             */
mq_uint8 dio_read_digital(mq_uint8 Port_u8, mq_uint8 Pin_u8)
{
  /* local variable used to store the result */
  mq_uint8 port_value_u8;
  /* declare a local mask */
  mq_uint8 Mask_pin_u8;
  
  port_value_u8 = PORT_INITIAL_VALUE;
   
  Mask_pin_u8 = PORT_INITIAL_VALUE;
  
  /* Mask the pin */
  Mask_pin_u8 |= PIN_VALUE_1 << Pin_u8;
  
  /* Switch between the ports */
  switch (Port_u8)
  {
          
        /* Case for PORTB */
          case PORT_A :
          {
                  /* Verify if the flag is set */
                  if((PINA & Mask_pin_u8) != 0)
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ONE_VALUE;
                  }
                  else
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ZERO_VALUE;
                  }
                  
          }
          break;

          /* Case for PORTB */
          case PORT_B :
          {
                  /* Verify if the flag is set */
                  if((PINB & Mask_pin_u8) != 0)
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ONE_VALUE;
                  }
                  else
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ZERO_VALUE;
                  }
                  break;
          }
          /* Case for PORTC */
          case PORT_C :
          {
                  /* Verify if the flag is set */
                  if((PINC & Mask_pin_u8) != 0)
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ONE_VALUE;
                  }
                  else
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ZERO_VALUE;
                  }
                  break;
          }
          
          /* Case for PORTD */
          case PORT_D :
          {
                  /* Verify if the flag is set  */
                  if((PIND & Mask_pin_u8) != 0)
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ONE_VALUE;
                  }
                  else
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ZERO_VALUE;
                  }
                  break;
          }

                    /* Case for PORTD */
          case PORT_E :
          {
                  /* Verify if the flag is set  */
                  if((PINE & Mask_pin_u8) != 0)
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ONE_VALUE;
                  }
                  else
                  {
                          /* Set the return value */
                          port_value_u8 = PORT_ZERO_VALUE;
                  }
                  break;
          }
          
          /* Default case */
          default:
                PORT_NOP
          break;
          
  }
  
  
  /* Return the value */
  return port_value_u8;
}

/* Routine used to write pin value at the desired address */
mq_uint8 dio_write_digital(mq_uint8 Port_u8, mq_uint8 Pin_u8, mq_uint8 Level_u8 )
{
 mq_uint8 ReturnValue_u8;
  /* Create the pin mask */
  mq_uint8 PinMask_u8; 
  mq_uint8 local_value;
  
  PinMask_u8 = PORT_ONE << Pin_u8;
 ReturnValue_u8 = OPERATION_SUCCESSFUL;
  
  /* Switch between the ports */
  switch (Port_u8)
  {
    /* Case for PORTB */
    case PORT_A :
    {
     if(Level_u8 == 1)
     {
        /* value of the PIN is HIGH */
        if((PORTA & PinMask_u8) == PinMask_u8)
        {
          /* Do nothing, the value is already one */
          MQ_NOP;
          
        }
        else
        {
          local_value = PINB;
          
          local_value |= PinMask_u8;
          /* Se the value as HIGH */
          PORTA |= local_value;
        }
      }
       /*  Desired level is 0*/
      else
      {
        local_value = PINB;
        /* Current level is 1 */
        if((local_value & PinMask_u8) != 0)
        {
                  
         local_value = (~PinMask_u8);
          
         PORTA &= local_value;
                 
        }
        else
        {
            /* Do nothing, the value is already zero */
          MQ_NOP;
          
        }
        
      }
      
    }
    /* Break case */
    break;

    /* Case for PORTB */
    case PORT_B :
    {
     if(Level_u8 == 1)
     {
        /* value of the PIN is HIGH */
        if((PORTB & PinMask_u8) == PinMask_u8)
        {
          /* Do nothing, the value is already one */
          MQ_NOP;
          
        }
        else
        {
          local_value = PINB;
          
          local_value |= PinMask_u8;
          /* Se the value as HIGH */
          PORTB |= local_value;
        }
      }
       /*  Desired level is 0*/
      else
      {
        local_value = PINB;
        /* Current level is 1 */
        if((local_value & PinMask_u8) != 0)
        {
                
          local_value = (~PinMask_u8);
          
          PORTB &= local_value;
          
        }
        else
        {
            /* Do nothing, the value is already zero */
          MQ_NOP;
          
        }
        
      }
      
    }
    /* Break case */
    break;
    
    /* Case for PORTC */
    case PORT_C :
    {
           if(Level_u8 == 1)
     {
        /* value of the PIN is HIGH */
        if(PORTC & PinMask_u8 == PinMask_u8)
        {
          /* Do nothing, the value is already one */
          MQ_NOP;
          
        }
        else
        {
          /* Se the value as HIGH */
          local_value = PINC;
          
          local_value |= PinMask_u8;
          /* Se the value as HIGH */
          PORTC |= local_value;
        }
      }
       /*  Desired level is 0*/
      else
      {  
          local_value = PINE;
        /* Current level is 1 */
        if((local_value & PinMask_u8) != 0)
        {
          local_value = (~PinMask_u8);
          
          PORTE &= local_value;
        }
        else
        {
            /* Do nothing, the value is already zero */
          MQ_NOP;
          
        }
        
      }
            
            break;
    }
    
    /* Case for PORTD */
    case PORT_D :
    {
     if(Level_u8 == 1)
     {
        /* value of the PIN is HIGH */
        if((PORTD & PinMask_u8) == PinMask_u8)
        {
          /* Do nothing, the value is already one */
          MQ_NOP;
          
        }
        else
        {
          local_value = PIND;
          
          local_value |= PinMask_u8;
          /* Se the value as HIGH */
          PORTD |= local_value;
        }
      }
       /*  Desired level is 0*/
      else
      {
        local_value = PIND;
        /* Current level is 1 */
        if((local_value & PinMask_u8) != 0)
        {
         local_value = (~PinMask_u8);
          
          PORTD &= local_value;
        }
        else
        {
            /* Do nothing, the value is already zero */
          MQ_NOP;
          
        }
        
      }
   
    break;
    }
    
    /* Case for PORTE */
      case PORT_E :
    {
     if(Level_u8 == 1)
     {
        /* value of the PIN is HIGH */
        if((PORTE & PinMask_u8) == PinMask_u8)
        {
          /* Do nothing, the value is already one */
          MQ_NOP;
          
        }
        else
        {
          local_value = PINE;
          
          local_value |= PinMask_u8;
          /* Se the value as HIGH */
          PORTE |= local_value;
        }
      }
       /*  Desired level is 0*/
      else
      {
        local_value = PINE;
        /* Current level is 1 */
        if((local_value & PinMask_u8) != 0)
        {

          
         local_value = (~PinMask_u8);
          
          PORTE &= local_value;
          
      
        }
        else
        {
            /* Do nothing, the value is already zero */
          MQ_NOP;
          
        }
        
      }
      
    }
    /* Break case */
    break;
    
    
    /* default case */
    default :
    {
          ReturnValue_u8 = ERROR_WITH_PARAMETERS;
            break;
    }
  
  }
  return ReturnValue_u8;
}




#if(ENABLE_TOOGLE_PIN == PORT_ENABLE)

/* Function to toggle the selected Pin  */
void dio_toggle_pin(mq_uint8 Port, mq_uint8 Pin)
{
	/* Mask of the pins */
	mq_uint8 PinMask_u8; 
        PinMask_u8 = 0;
	
	/* Create a mask for the Pin value */
	PinMask_u8 &= 1 << Pin;
	/* Switch between the ports */
	switch(Port)
	{

        /* Case for PORTB */
    case PORT_A :
    {
      /* Verify if the PORTB's Pin is set */
      if((PORTA & PinMask_u8) != 0)
      {
        /* Set the pin to value 0 */
        PORTA &= 0<<Pin;
      }
      else
      {
        /* Set the Pin to value 1 */
        PORTA |= 1<<Pin;
      }
      
    }
    break;
		/* Case for PORTB */
		case PORT_B :
		{
			/* Verify if the PORTB's Pin is set */
			if((PORTB & PinMask_u8) != 0)
			{
				/* Set the pin to value 0 */
				PORTB &= 0<<Pin;
			}
			else
			{
				/* Set the Pin to value 1 */
				PORTB |= 1<<Pin;
			}
			
		}
		break;
		
		/* Case for PORTC */
		case PORT_C :
		{
			/* Verify if the PORTB's Pin is set */
			if((PORTC & PinMask_u8) != 0)
			{
				/* Set the pin to value 0 */
				PORTC &= 0<<Pin;
			}
			else
			{
				/* Set the Pin to value 1 */
				PORTC |= 1<<Pin;
			}
		}
		break;
		
		/* Case for PORTD */
		case PORT_D :
		{
			/* Verify if the PORTB's Pin is set */
			if((PORTD & PinMask_u8) != 0)
			{
				/* Set the pin to value 0 */
				PORTD &= 0<<Pin;
			}
			else
			{
				/* Set the Pin to value 1 */
				PORTD |= 1<<Pin;
			}
		}
		break;

        /* Case for PORTE */
    case PORT_E :
    {
      /* Verify if the PORTE's Pin is set */
      if((PORTE & PinMask_u8) != 0)
      {
        /* Set the pin to value 0 */
        PORTE &= 0<<Pin;
      }
      else
      {
        /* Set the Pin to value 1 */
        PORTE |= 1<<Pin;
      }
    }
    break;
                
                /* Default case */
		default:
                      PORT_NOP
		break;
	}
}

#endif


/*
_______________________________________________________________________________
|----------------------------- ISR ROUTINS ------------------------------------|
|______________________________________________________________________________|
*/

#if (ENABLE_INTERRUPT_INT0 == DIO_ENABLE)

  #if(COMPILER == IAR)

	#pragma vector=INT0_vect
        #pragma type_attribute = __interrupt
        void INT0_vect_interrupt(void)
  #else
        ISR(INT0_vect)
  #endif
	{
		int0_interrupt_callback();
	}

#endif

#if (ENABLE_INTERRUPT_INT1 == DIO_ENABLE)
        
  #if(COMPILER == IAR)
        #pragma vector=INT1_vect
        #pragma type_attribute = __interrupt
        void INT1_vect_interrupt(void)
  #else
        ISR(INT1_vect)
  #endif
        {
                
                int1_interrupt_callback();
                
        }
          
#endif

#if (ENABLE_INTERRUPT_PORTA == PORT_ENABLE)

  #pragma vector=PCINT0_vect
        #pragma type_attribute = __interrupt
        void PCINT0_vect_interrupt(void)


  {
    
  interrupt_flag_u8 = MQ_ENABLED;
  
   
  }
#endif

void dio_interrupt_PORTA_handling(void)
{
  
 /* Local iterator */
    mq_uint8 local_counter_u8;
  
    /* New information about the values from the PCINT[0:7] */
    mq_uint8 PCMSK0_data_new_u8; 
  
    /* Local mask for the pins */
    mq_uint8 MaskPin_u8;
    
    PCMSK0_data_new_u8 = PORT_INITIAL_VALUE;
    /* Local temporary pin value */
    mq_uint8 temp_PinValue_u8 = PORT_INITIAL_VALUE;
   
    if(interrupt_flag_u8 == MQ_ENABLED){
    /* Iteration throw all pins from the PCMSK0 and PCINT[0:7] */
    for(local_counter_u8 = PORT_ZERO;local_counter_u8 < PORT_MAX_PORTB_REGISTER_PIN;local_counter_u8++)
    {
      /* Set the local pin mask to 0 */
      MaskPin_u8 = PORT_INITIAL_VALUE;
    
      /* Set the mask with the position of the local counter as flag */
      MaskPin_u8 |= 1<<local_counter_u8;
    
      /* Verify if that position is enabled to generate a interrupt  */
      if((PCMSK0 & MaskPin_u8) != PORT_ZERO)
      {
        /* read the value of that pin position */
        temp_PinValue_u8 = dio_read_digital(PORT_A,local_counter_u8);
      
        /* Set the temporary value in the PCMSK0_data_new_u8 register on the designated position */
        PCMSK0_data_new_u8 |= (temp_PinValue_u8 << local_counter_u8);
      
        #if( EDGE_INTERRUPT0_ENABLE == PORT_ENABLE)
      
        /* verify if the new value is different from the old one and the new value is 0 in order to detect a falling edge trigger  */
        if((temp_PinValue_u8 == 0) && ((interrupt_PORTA_falling & MaskPin_u8)!= 0))
        {
          /* Call the callback for falling edge */
          pcint0_interrupt_callback_falling_edge(local_counter_u8);
        }
        else
        {
          /* verify if the old value is 0V and the new one is 1 in order to trigger a rising edge */
          if((temp_PinValue_u8 == 1)&& ((interrupt_PORTA_rising & MaskPin_u8)!= 0))
          {
            /*Call the callback for rising edge */
            pcint0_interrupt_callback_rising_edge(local_counter_u8);
          }else
          {
            /* Do nothing*/
            PORT_NOP
          }
        }
        
        #else
        
          if((( PCMSK0_data_old_u8 | PCMSK0_data_new_u8) != 0 )&&(PCMSK0_data_old_u8 != PCMSK0_data_new_u8 ))
          {
             pcint0_interrupt_callback(local_counter_u8);
          }
          else
          {
            PORT_NOP
          }
        
        #endif
      
      }
    }
    
    /* Store the old data */
    PCMSK0_data_old_u8 = PCMSK0_data_new_u8;
    
    interrupt_flag_u8 = MQ_DISABLED;
    }
    else
    {
    MQ_NOP;
    }
 
}

#if (ENABLE_INTERRUPT_PORTB == PORT_ENABLE)
#if(COMPILER == IAR)
	#pragma vector=PCINT1_vect
        #pragma type_attribute = __interrupt
        void PCINT1_vect_interrupt(void)
#else
       ISR(PCINT1_vect)
#endif
	{
		/* Local iterator */
		mq_uint8 local_counter_u8;
	
		/* New information about the values from the PCINT[0:7] */
		mq_uint8 PCMSK1_data_new_u8; 
	
		/* Local mask for the pins */
		mq_uint8 MaskPin_u8;
                
                PCMSK1_data_new_u8 = PORT_INITIAL_VALUE;
		/* Local temporary pin value */
		mq_uint8 temp_PinValue_u8 = PORT_INITIAL_VALUE;
	
		/* Iteration throw all pins from the PCMSK0 and PCINT[0:7] */
		for(local_counter_u8 = PORT_ZERO;local_counter_u8 < PORT_MAX_PORTB_REGISTER_PIN;local_counter_u8++)
		{
			/* Set the local pin mask to 0 */
			MaskPin_u8 = PORT_INITIAL_VALUE;
		
			/* Set the mask with the position of the local counter as flag */
			MaskPin_u8 |= 1<<local_counter_u8;
		
			/* Verify if that position is enabled to generate a interrupt  */
			if((PCMSK1 & MaskPin_u8) != PORT_ZERO)
			{
				/* read the value of that pin position */
				temp_PinValue_u8 = dio_read_digital(PORT_B,local_counter_u8);
			
				/* Set the temporary value in the PCMSK0_data_new_u8 register on the designated position */
				PCMSK1_data_new_u8 |= (temp_PinValue_u8 << local_counter_u8);
			
				#if( EDGE_INTERRUPT0_ENABLE == PORT_ENABLE)
			
				/* verify if the new value is different from the old one and the new value is 0 in order to detect a falling edge trigger  */
				if(/*((PCMSK0_data_old_u8 & MaskPin_u8) != 0 ) && */(temp_PinValue_u8 == 0) && ((interrupt_pc1_falling & MaskPin_u8)!= 0))
				{
					/* Call the callback for falling edge */
					pcint1_interrupt_callback_falling_edge(local_counter_u8);
				}
				else
				{
					/* verify if the old value is 0V and the new one is 1 in order to trigger a rising edge */
					if(/*((PCMSK0_data_old_u8 & MaskPin_u8) == 0) && */(temp_PinValue_u8 == 1)&& ((interrupt_pc1_rising & MaskPin_u8)!= 0))
					{
						/*Call the callback for rising edge */
						pcint1_interrupt_callback_rising_edge(local_counter_u8);
					}else
					{
						/* Do nothing*/
						PORT_NOP
					}
				}
				
				#else
				
					if((( PCMSK1_data_old_u8 | PCMSK1_data_new_u8) != 0 )&&(PCMSK1_data_old_u8 != PCMSK1_data_new_u8 ))
					{
						 pcint1_interrupt_callback(local_counter_u8);
					}
					else
					{
						PORT_NOP
					}
				
				#endif
			
			}
		}
		/* Store the old data */
		PCMSK1_data_old_u8 = PCMSK1_data_new_u8;
	
	}
#endif

#if (ENABLE_INTERRUPT_PORTC == PORT_ENABLE)

#if(COMPILATOR == IAR)
	#pragma vector=PCINT2_vect
        #pragma type_attribute = __interrupt
        void PCINT2_vect_interrupt(void)
#else
      ISR(PCINT2_vect)
#endif
	{
		/* Local iterator */
		mq_uint8 local_counter_u8;
	
		/* New information about the values from the PCINT[8:14] */
		mq_uint8 PCMSK2_data_new_u8; 
	
		/* Local mask for the pins */
		mq_uint8 MaskPin_u8;
                
                PCMSK2_data_new_u8 = PORT_INITIAL_VALUE;
		/* Local temporary pin value */
		mq_uint8 temp_PinValue_u8 = PORT_INITIAL_VALUE;
	
		/* Iteration throw all the pins */
		for(local_counter_u8 = PORT_ZERO;local_counter_u8 < PORT_MAX_PORTC_REGISTER_PIN;local_counter_u8++)
		{
			/* Set the Pin mask to zero*/
			MaskPin_u8 = 0;
		
			/* Set the mask with the current position of the counter */
			MaskPin_u8 |= 1<<local_counter_u8;
		
			/* Verify if the current position is enabled as interrupt */
			if((PCMSK2 & MaskPin_u8) != 0)
			{
				/* Get in the temporary value the value of the pin */
				temp_PinValue_u8 = dio_read_digital(PORT_C,local_counter_u8);
			
				/* Set the new value in the data new register */
				PCMSK2_data_new_u8 |= (temp_PinValue_u8 << local_counter_u8);
						
					/* Verify if the old value is different from 0 and the new one is 0 in order to trigger the falling edge callback */
					if(((PCMSK2_data_old_u8 & MaskPin_u8) != 0 ) && (temp_PinValue_u8 == 0))
					{
						/* Call the falling edge callback */
						pcint2_interrupt_callback_falling_edge(local_counter_u8);
				
					}
					else
			
					{
						/* Verify if old value is 0 and the new one is 1 in order to trigger a rising edge callback*/
						if(((PCMSK2_data_old_u8 & MaskPin_u8) == 0) && (temp_PinValue_u8 == 1))
						{
							/* Call the rising edge callback */
							pcint2_interrupt_callback_rising_edge(local_counter_u8);
					
						}
						else
						{
							/* Do nothing*/
							PORT_NOP
						}
					}
			}
		}
	
		PCMSK2_data_old_u8 = PCMSK2_data_new_u8;
	}

#endif

#if (ENABLE_INTERRUPT_PORTD == PORT_ENABLE)

#if(COMPILER == IAR)
	#pragma vector=PCINT3_vect
        #pragma type_attribute = __interrupt
        void PCINT3_vect_interrupt(void)
#else
       ISR(PCINT3_vect)
#endif
	{
		/* Local iterator */
		mq_uint8 local_counter_u8;
	
		/* New information about the values from the PCINT[16:23] */
		mq_uint8 PCMSK3_data_new_u8; 
	
		/* Local mask for the pins */
		mq_uint8 MaskPin_u8;
	
                PCMSK3_data_new_u8 = PORT_ZERO;
		/* Local temporary pin value */
		mq_uint8 temp_PinValue_u8 = PORT_INITIAL_VALUE;
	
		/* Iterate throw all the flags of the register*/
		for(local_counter_u8 = 0;local_counter_u8 < PORT_MAX_PORTD_REGISTER_PIN;local_counter_u8++)
		{
			/* Initialize the pin mask */
			MaskPin_u8 = 0;
		
			/*Set the mask */
			MaskPin_u8 |= 1<<local_counter_u8;
		
			/* verify if that position has it's interrupt enabled */
			if((PCMSK3 & MaskPin_u8) != 0)
			{
				/* Get the current value from the pin */
				temp_PinValue_u8 = dio_read_digital(PORT_D,local_counter_u8);
			
				/* Set the value in the new register */
				PCMSK3_data_new_u8 |= (temp_PinValue_u8 << local_counter_u8);
			
				/* Verify if the old value is different from 0 and the new one is 0 in order to trigger a falling edge interrupt callback */
				if(((PCMSK3_data_old_u8 & MaskPin_u8) != 0 ) && (temp_PinValue_u8 == 0))
				{
					/*  Falling edge callback */
					pcint3_interrupt_callback_falling_edge(local_counter_u8);
				}
			
				else
				{
					/* Verify if the old value is 0 and the new one is 1 in order to trigger a rising edge interrupt callback */
					if(((PCMSK3_data_old_u8 & MaskPin_u8) == 0) && (temp_PinValue_u8 == 1))
					{
						/* Rising edge callback */
						pcint3_interrupt_callback_rising_edge(local_counter_u8);
					}
					else
					{
						/* Do nothing*/
						PORT_NOP
					}
				}
			
			
			}
		}
	
		/* Store the new data */
		PCMSK3_data_old_u8 = PCMSK3_data_new_u8;
	}

#endif

#if (ENABLE_INTERRUPT_PORTE == PORT_ENABLE)

#if(COMPILER == IAR)
  #pragma vector=PCINT4_vect
        #pragma type_attribute = __interrupt
        void PCINT4_vect_interrupt(void)
#else
       ISR(PCINT4_vect)
#endif
  {
    /* Local iterator */
    mq_uint8 local_counter_u8;
  
    /* New information about the values from the PCINT[16:23] */
    mq_uint8 PCMSK4_data_new_u8; 
  
    /* Local mask for the pins */
    mq_uint8 MaskPin_u8;
    
    mq_uint8 temp_PinValue_u8;
    
    PCMSK4_data_new_u8 = PORT_ZERO;
    /* Local temporary pin value */
    temp_PinValue_u8 = PORT_INITIAL_VALUE;
  
    /* Iterate throw all the flags of the register*/
    for(local_counter_u8 = 0;local_counter_u8 < PORT_MAX_PORTE_REGISTER_PIN;local_counter_u8++)
    {
      /* Initialize the pin mask */
      MaskPin_u8 = 0;
    
      /*Set the mask */
      MaskPin_u8 |= 1<<local_counter_u8;
    
      /* verify if that position has it's interrupt enabled */
      if((PCMSK4 & MaskPin_u8) != 0)
      {
        /* Get the current value from the pin */
        temp_PinValue_u8 = dio_read_digital(PORT_E,local_counter_u8);
      
        /* Set the value in the new register */
        PCMSK4_data_new_u8 |= (temp_PinValue_u8 << local_counter_u8);
      
        /* Verify if the old value is different from 0 and the new one is 0 in order to trigger a falling edge interrupt callback */
        if(((PCMSK4_data_old_u8 & MaskPin_u8) != 0 ) && (temp_PinValue_u8 == 0))
        {
          /*  Falling edge callback */
          pcint4_interrupt_callback_falling_edge(local_counter_u8);
        }
      
        else
        {
          /* Verify if the old value is 0 and the new one is 1 in order to trigger a rising edge interrupt callback */
          if(((PCMSK4_data_old_u8 & MaskPin_u8) == 0) && (temp_PinValue_u8 == 1))
          {
            /* Rising edge callback */
            pcint4_interrupt_callback_rising_edge(local_counter_u8);
          }
          else
          {
            /* Do nothing*/
            PORT_NOP
          }
        }
      
      
      }
    }
  
    /* Store the new data */
    PCMSK4_data_old_u8 = PCMSK4_data_new_u8;
  }

#endif
