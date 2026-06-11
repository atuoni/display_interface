/*
 * screen_2.c
 *
 *  Created on: 9 de jun. de 2026
 *      Author: amtuo
 */

#include "screen_2.h"
#include "main.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"


/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen2_menu[] =
{
		 { "A1", MENU_LABEL, MENU_ID_NONE, NULL},
		 { "A2", MENU_LABEL, MENU_ID_NONE, NULL},
		 { "A3", MENU_LABEL, MENU_ID_NONE, NULL},
		 {"Back", MENU_NAVIGATION, SCREEN_1, NULL}
};

#define SCREEN2_COUNT (sizeof(screen2_menu)/sizeof(screen2_menu[0]))

/*------------------------------------------------------------------
 * Item selecionado
 *-----------------------------------------------------------------*/
static uint8_t selected = 0;

/*------------------------------------------------------------------
 * Protótipos privados
 *-----------------------------------------------------------------*/
static void screen2_draw(void);
static void screen2_event(void);

/*------------------------------------------------------------------
 * Objeto da tela
 *-----------------------------------------------------------------*/
Screen_t screen_2 =
{
    .draw  = screen2_draw,
    .event = screen2_event
};

/*------------------------------------------------------------------
 * Inicialização
 *-----------------------------------------------------------------*/
void screen2_init(void)
{
    selected = 0;
}

/*------------------------------------------------------------------
 * Desenha tela
 *-----------------------------------------------------------------*/
static void screen2_draw(void)
{
    menu_widget_draw("SCREEN 2",screen2_menu,SCREEN2_COUNT,selected);
}

/*------------------------------------------------------------------
 * Eventos
 *-----------------------------------------------------------------*/
static void screen2_event(void)
{
    menu_widget_event(screen2_menu, SCREEN2_COUNT, &selected);
}
