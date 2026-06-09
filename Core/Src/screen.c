/*
 * screen.c
 *
 *  Created on: 8 de jun. de 2026
 *      Author: amtuo
 */

#include "screen.h"
#include "screen_1.h"
#include "screen_2.h"
#include "screen_4.h"
#include "screen_3.h"
#include "screen_5.h"

Screen_t *screen_table[SCREEN_COUNT] =
{
    [SCREEN_1] = &screen_1,
    [SCREEN_2] = &screen_2,
    [SCREEN_3] = &screen_3,
	[SCREEN_4] = &screen_4,
	[SCREEN_5] = &screen_5
};

void screen_init(void)
{
    screen1_init();
    screen2_init();
    screen3_init();
    screen4_init();
    screen5_init();
}
