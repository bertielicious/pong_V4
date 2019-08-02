#include "config.h"
#include "pixel.h"
#include "unpixel.h"
#include <stdio.h>
#include <stdbool.h>
uchar move_ball (uchar x, uchar y, bool erase)
{
    
    pixel(x, y, erase);
    pixel(x, y+1, erase);
    pixel(x, y+2, erase);
    
    pixel(x+1, y, erase);
    pixel(x+1, y+1, erase);
    pixel(x+1, y+2, erase);
    
    pixel(x+2, y, erase);
    pixel(x+2, y+1, erase);
    pixel(x+2, y+2, erase);
    
    pixel(x+3, y, erase);
    pixel(x+3, y+1, erase);
    pixel(x+3, y+2, erase);
   
    
    pixel(x, y, !erase);
    pixel(x, y+1, !erase);
    pixel(x, y+2, !erase);
    
    
    
    
}