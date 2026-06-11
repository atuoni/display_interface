/*
 * screen_4.c
 *
 *  Created on: 9 de jun. de 2026
 *      Author: amtuo
 */

#include "screen_4.h"
#include "main.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"


/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen4_menu[] =
{
		 { "C1", MENU_LABEL, MENU_ID_NONE, NULL},
		 { "C2", MENU_LABEL, MENU_ID_NONE, NULL},
		 { "C3", MENU_NAVIGATION, SCREEN_5, NULL},
		 {"Back", MENU_NAVIGATION, SCREEN_1, NULL}
};

#define SCREEN4_COUNT (sizeof(screen4_menu)/sizeof(screen4_menu[0]))

/*------------------------------------------------------------------
 * Item selecionado
 *-----------------------------------------------------------------*/
static uint8_t selected = 0;

/*------------------------------------------------------------------
 * Protótipos privados
 *-----------------------------------------------------------------*/
static void screen4_draw(void);
static void screen4_event(void);

/*------------------------------------------------------------------
 * Objeto da tela
 *-----------------------------------------------------------------*/
Screen_t screen_4 =
{
    .draw  = screen4_draw,
    .event = screen4_event
};

/*------------------------------------------------------------------
 * Inicialização
 *-----------------------------------------------------------------*/
void screen4_init(void)
{
    selected = 0;
}

/*------------------------------------------------------------------
 * Desenha tela
 *-----------------------------------------------------------------*/
static void screen4_draw(void)
{
    menu_widget_draw("SCREEN 4",screen4_menu,SCREEN4_COUNT,selected);
}

/*------------------------------------------------------------------
 * Eventos
 *-----------------------------------------------------------------*/
static void screen4_event(void)
{
    menu_widget_event(screen4_menu, SCREEN4_COUNT, &selected);
}
