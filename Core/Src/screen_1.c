/*
 * screen_1.c
 *
 *  Created on: 9 de jun. de 2026
 *      Author: amtuo
 */

#include "screen_1.h"
#include "menu.h"
#include "menu_widget.h"
#include "main.h"

/*------------------------------------------------------------------
 * Protótipos
 *-----------------------------------------------------------------*/
static void screen1_draw(void);
static void screen1_event(void);
static void led_toggle(void);


/*------------------------------------------------------------------
 * Tabela
 *-----------------------------------------------------------------*/
static MenuItem_t screen1_menu[] =
{
    { "A", MENU_NAVIGATION, SCREEN_2, NULL},
    { "B", MENU_NAVIGATION, SCREEN_3, NULL},
    { "C", MENU_NAVIGATION, SCREEN_4, NULL},
	{ "LED: OFF", MENU_ACTION, 0, led_toggle}
};

#define SCREEN1_COUNT (sizeof(screen1_menu)/sizeof(screen1_menu[0]))

static uint8_t selected = 0;
static uint8_t led_state = 0;


/*------------------------------------------------------------------
 * Tela
 *-----------------------------------------------------------------*/
Screen_t screen_1 =
{
    .draw  = screen1_draw,
    .event = screen1_event
};

/*------------------------------------------------------------------
 * Init
 *-----------------------------------------------------------------*/
void screen1_init(void)
{
    selected = 0;
}

/*------------------------------------------------------------------
 * Draw
 *-----------------------------------------------------------------*/
static void screen1_draw(void)
{
    menu_widget_draw("SCREEN 1",screen1_menu,SCREEN1_COUNT,selected);
}

/*------------------------------------------------------------------
 * Event
 *-----------------------------------------------------------------*/
static void screen1_event(void)
{
    menu_widget_event(screen1_menu, SCREEN1_COUNT, &selected);
}
static void led_toggle(void)
{
    led_state = !led_state;

    HAL_GPIO_WritePin(LED_Pin_GPIO_Port,LED_Pin_Pin,led_state ? GPIO_PIN_SET : GPIO_PIN_RESET);

    screen1_menu[3].text = led_state ? "LED: ON" : "LED: OFF";

    menu_widget_redraw_item(screen1_menu, 3, (selected == 3));
}
