/*
 * screen_3.c
 *
 *  Created on: 9 de jun. de 2026
 *      Author: amtuo
 */

#include "screen_3.h"
#include "main.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"


/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen3_menu[] =
{
		 { "B1", MENU_LABEL, MENU_ID_NONE, NULL},
	     { "B2", MENU_LABEL, MENU_ID_NONE, NULL},
		 { "B3", MENU_LABEL, MENU_ID_NONE, NULL},
		 {"Voltar", MENU_NAVIGATION, SCREEN_1, NULL}
};

#define SCREEN3_COUNT (sizeof(screen3_menu)/sizeof(screen3_menu[0]))

/*------------------------------------------------------------------
 * Item selecionado
 *-----------------------------------------------------------------*/
static uint8_t selected = 0;

/*------------------------------------------------------------------
 * Protótipos privados
 *-----------------------------------------------------------------*/
static void screen3_draw(void);
static void screen3_event(void);

/*------------------------------------------------------------------
 * Objeto da tela
 *-----------------------------------------------------------------*/
Screen_t screen_3 =
{
    .draw  = screen3_draw,
    .event = screen3_event
};

/*------------------------------------------------------------------
 * Inicialização
 *-----------------------------------------------------------------*/
void screen3_init(void)
{
    selected = 0;
}

/*------------------------------------------------------------------
 * Desenha tela
 *-----------------------------------------------------------------*/
static void screen3_draw(void)
{
    menu_widget_draw("SCREEN 3",screen3_menu,SCREEN3_COUNT,selected);
}

/*------------------------------------------------------------------
 * Eventos
 *-----------------------------------------------------------------*/
static void screen3_event(void)
{
    menu_widget_event(screen3_menu, SCREEN3_COUNT, &selected);
}
