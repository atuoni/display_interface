/**
 ******************************************************************************
 * @file    menu.c
 * @brief   Gerenciador de telas
 ******************************************************************************
 */

#include <screen_1.h>
#include <stddef.h>
#include "menu.h"
#include "screen_2.h"
#include "screen_3.h"
#include "screen_4.h"
#include "screen_5.h"


/*----------------------------------------------------------
 * Tela atual
 *---------------------------------------------------------*/
static Screen_t *current_screen = NULL;

/*----------------------------------------------------------
 * Inicialização
 *---------------------------------------------------------*/
void menu_init(void)
{
    current_screen = screen_table[SCREEN_1];
}

/*----------------------------------------------------------
 * Desenha tela atual
 *---------------------------------------------------------*/
void menu_draw(void)
{
    if(current_screen != NULL)
    {
        current_screen->draw();
    }
}

/*----------------------------------------------------------
 * Processa eventos da tela atual
 *---------------------------------------------------------*/
void menu_event(void)
{
    if(current_screen != NULL)
    {
        current_screen->event();
    }
}

/*----------------------------------------------------------
 * Troca de tela
 *---------------------------------------------------------*/
void menu_change(ScreenId_t id)
{
    if(id >= SCREEN_COUNT)
    {
        return;
    }

    current_screen = screen_table[id];

    current_screen->draw();
}
