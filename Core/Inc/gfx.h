/*
 * gfx.h
 *
 *  Created on: 8 de jun. de 2026
 *      Author: amtuo
 */
#ifndef GFX_H
#define GFX_H

#include "tft.h"

#define GFX_PRINT(x,y,color,text) \
do                                \
{                                 \
    tft_setCursor(x,y);           \
    tft_setTextColor(color);      \
    tft_printstr((uint8_t*)text); \
} while(0)

#endif
