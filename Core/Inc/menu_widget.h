#ifndef MENU_WIDGET_H
#define MENU_WIDGET_H

#include <stdint.h>

#define MENU_ID_NONE 255

typedef enum
{
    MENU_NAVIGATION,
    MENU_ACTION,
    MENU_LABEL

}MenuType_t;

/*------------------------------------------------------------------
 * Callback de ação
 *-----------------------------------------------------------------*/
typedef void (*MenuAction_t)(void);

/*------------------------------------------------------------------
 * Item de menu genérico
 *-----------------------------------------------------------------*/
typedef struct
{
    const char *text;
    MenuType_t  type;
    uint8_t     id;
    MenuAction_t action;

}MenuItem_t;

/*------------------------------------------------------------------
 * API
 *-----------------------------------------------------------------*/
void menu_widget_draw(const char *title, const MenuItem_t *items, uint8_t count, uint8_t selected);

void menu_widget_update(const MenuItem_t *items, uint8_t old_idx, uint8_t new_idx);

/* Atualiza somente um item */
void menu_widget_redraw_item(const MenuItem_t *items, uint8_t idx, uint8_t selected);

void menu_widget_event(const MenuItem_t *items, uint8_t count, uint8_t *selected);

#endif
