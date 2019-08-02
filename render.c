#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
#include <stdio.h>

void render(struct pageData s, bool erase)      //render receives the entire struct containing page, date, x and y
{
     set_address( s.x, s.page);               //[row][col]
     if(erase == 1)
     {
         gameplay_area[s.page][s.x] = gameplay_area[s.page][s.x]&0x00;      // clear the ball data from gameplay_area[][]]
     }
     else if (erase == 0)
     {
        gameplay_area[s.page][s.x] = gameplay_area[s.page][s.x]|(s.data);       // write the ball data to gameplay_area[][]]
     }
     
     lcdWrite(gameplay_area[s.page][s.x], HIGH);       // refresh the LCD with the latest version of gameplay_area[][] 
     //lcdWrite(gameplay_area[s.page][s.x]&s.data, HIGH);
    // printf("data = %d, erase = %d\n", s.data, erase);
}
