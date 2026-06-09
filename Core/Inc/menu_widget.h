#ifndef MENU_WIDGET_H
#define MENU_WIDGET_H

#include <stdint.h>

/*------------------------------------------------------------------
 * Item de menu genérico
 *-----------------------------------------------------------------*/
typedef struct
{
    const char *text;
    uint8_t     id;

}MenuItem_t;

/*------------------------------------------------------------------
 * API
 *-----------------------------------------------------------------*/
void menu_widget_draw(const char *title, const MenuItem_t *items, uint8_t count, uint8_t selected);

void menu_widget_update(const MenuItem_t *items, uint8_t old_idx, uint8_t new_idx);

#endif
