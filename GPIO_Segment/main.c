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

// https://ppfocus.com/0/ho2a28e2c.html

#include "gd32f30x.h"
#include "gd32f303c_eval.h"
#include "systick.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/

uint32_t segment[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7D, 0x07, 0x7f, 0x6F};

void gpio_config(void)
{
		rcu_periph_clock_enable(RCU_GPIOD);
		gpio_init(GPIOD, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_ALL);

//		gpio_bit_write (GPIOD, GPIO_PIN_0, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_1, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_2, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_3, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_4, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_5, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_6, SET);
//		gpio_bit_write (GPIOD, GPIO_PIN_7, SET);
	
//		gpio_port_write(GPIOD,0x06);
	
}

int main(void)
{  	
		int i;
	
		gpio_config();
	
		systick_config();

		while(1){			
				for(i=0; i<=9; i++){
						gpio_port_write(GPIOD, segment[i]);
						delay_1ms(1000);
				}

		}
}
