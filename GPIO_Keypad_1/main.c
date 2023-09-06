/*!
    \file    main.c
    \brief   GPIO running led

    \version 2021-03-23, V2.0.0, demo for GD32F30x
*/

/*
    Copyright (c) 2021, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#include "gd32f30x.h"
#include "gd32f303c_eval.h"
#include "systick.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/

//FlagStatus C0, C1, C2, C3, C4, C5, C6, C7;

uint32_t segment[]={0x06, 0x5b, 0x4f, 0x77,   // 1 2 3 A
										0x66, 0x6d, 0x7D, 0x7c,   // 4 5 6 b
										0x07, 0x7f, 0x6F, 0x39,   // 7 8 9 C
										0x79, 0x3f, 0x5e, 0x71};  // E 0 F d

void keypad_config(void)
{
		rcu_periph_clock_enable(RCU_GPIOB);	
		gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_ALL);
//		gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
		
//		C0 = gpio_input_bit_get(GPIOB, GPIO_PIN_0);
//		C1 = gpio_input_bit_get(GPIOB, GPIO_PIN_1);
//		C2 = gpio_input_bit_get(GPIOB, GPIO_PIN_2);
//		C3 = gpio_input_bit_get(GPIOB, GPIO_PIN_3);
//		C4 = gpio_input_bit_get(GPIOB, GPIO_PIN_4);
//		C5 = gpio_input_bit_get(GPIOB, GPIO_PIN_5);
//		C6 = gpio_input_bit_get(GPIOB, GPIO_PIN_6);
//		C7 = gpio_input_bit_get(GPIOB, GPIO_PIN_7);	
}			

void display_config(void)
{
		rcu_periph_clock_enable(RCU_GPIOD);
		gpio_init(GPIOD, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_ALL);
}

int main(void)
{  		
		keypad_config();

		display_config();
		
		systick_config();
	
		while(1)
		{
				if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_0)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_0)){
                gpio_port_write(GPIOD, segment[13]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_0));
            }
				}
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_1)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_1)){
                gpio_port_write(GPIOD, segment[0]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_1));
            }
				}
				// PS. PB2 can't be used.
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_8)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_8)){
                gpio_port_write(GPIOD, segment[1]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_8));
            }
				}
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_3)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_3)){
                gpio_port_write(GPIOD, segment[2]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_3));
            }
				}
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_4)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_4)){
                gpio_port_write(GPIOD, segment[4]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_4));
            }
				}
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_5)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_5)){
                gpio_port_write(GPIOD, segment[5]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_5));
            }						
				}
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_6)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_6)){
                gpio_port_write(GPIOD, segment[6]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_6));
            }
				}
				else if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_7)){
						delay_1ms(50);
						if(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_7)){
                gpio_port_write(GPIOD, segment[8]);
                while(RESET == gpio_input_bit_get(GPIOB, GPIO_PIN_7));
            }
				}
    }
}
