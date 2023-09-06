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

uint32_t segment[]={0x06, 0x5b, 0x4f, 0x77,   // 1 2 3 A
										0x66, 0x6d, 0x7D, 0x7c,   // 4 5 6 b
										0x07, 0x7f, 0x6F, 0x39,   // 7 8 9 C
										0x79, 0x3f, 0x5e, 0x71};  // E 0 F d
										
void segment_config(void)
{
		rcu_periph_clock_enable(RCU_GPIOD);
		gpio_init(GPIOD, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_ALL);
}

int main(void)
{  			
		gd_eval_key_init(KEY_TAMPER, KEY_MODE_GPIO);
		gd_eval_key_init(KEY_USER, KEY_MODE_GPIO);
		gd_eval_key_init(KEY_WAKEUP, KEY_MODE_GPIO);
	
		segment_config();
	
		systick_config();

		while(1){
				if(RESET == gd_eval_key_state_get(KEY_WAKEUP)){
            /* delay 50ms for software removing jitter */
            delay_1ms(50);
            gpio_port_write(GPIOD, segment[15]);
        }
			
				else if(RESET == gd_eval_key_state_get(KEY_TAMPER)){
            /* delay 50ms for software removing jitter */
            delay_1ms(50);
            gpio_port_write(GPIOD, segment[10]);
        }
				else if(RESET == gd_eval_key_state_get(KEY_USER)){
            /* delay 50ms for software removing jitter */
            delay_1ms(50);
            gpio_port_write(GPIOD, segment[5]);
        }
    }
}
