/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 20 July 2019, 11:07
 */
/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include <math.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "clear_screen.h"
#include "pixel.h"
#include "set_address.h"
#include <stdbool.h>
#include "set_game_area.h"
#include "move_ball.h"
#include "TMR1_setup.h"



void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
clear_screen();
set_game_area();
TMR1_setup();
uchar i,j, row = 0;
//printf("Hello Phil!\n");
row = 16;
for ( i = 0; i < 81; i++)
{
    move_ball(i,row,0);
    if (i%2 == 0)
    {
        row++;
    }
}

while(1)
    {
    
    }       
}
