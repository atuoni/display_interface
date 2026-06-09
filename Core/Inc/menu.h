#ifndef MENU_H
#define MENU_H

#include "screen.h"

void menu_init(void);
void menu_draw(void);
void menu_event(void);
void menu_change(ScreenId_t id);

#endif
