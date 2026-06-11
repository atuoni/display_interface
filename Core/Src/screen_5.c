/*
 * screen_5.c
 *
 *  Created on: 9 de jun. de 2026
 *      Author: amtuo
 */

#include "screen_5.h"
#include "main.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"


/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen5_menu[] =
{
		{ "C3X", MENU_LABEL, MENU_ID_NONE, NULL},
	    { "C3Y", MENU_LABEL, MENU_ID_NONE, NULL},
	    { "C3Z", MENU_LABEL, MENU_ID_NONE, NULL},
	    {"Voltar", MENU_NAVIGATION, SCREEN_4, NULL}
};

#define SCREEN5_COUNT (sizeof(screen5_menu)/sizeof(screen5_menu[0]))

/*------------------------------------------------------------------
 * Item selecionado
 *-----------------------------------------------------------------*/
static uint8_t selected = 0;

/*------------------------------------------------------------------
 * Protótipos privados
 *-----------------------------------------------------------------*/
static void screen5_draw(void);
static void screen5_event(void);

/*------------------------------------------------------------------
 * Objeto da tela
 *-----------------------------------------------------------------*/
Screen_t screen_5 =
{
    .draw  = screen5_draw,
    .event = screen5_event
};

/*------------------------------------------------------------------
 * Inicialização
 *-----------------------------------------------------------------*/
void screen5_init(void)
{
    selected = 0;
}

/*------------------------------------------------------------------
 * Desenha tela
 *-----------------------------------------------------------------*/
static void screen5_draw(void)
{
    menu_widget_draw("SCREEN 5",screen5_menu,SCREEN5_COUNT,selected);
}

/*------------------------------------------------------------------
 * Eventos
 *-----------------------------------------------------------------*/
static void screen5_event(void)
{
    menu_widget_event(screen5_menu, SCREEN5_COUNT, &selected);
}

