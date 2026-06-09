/*
 * screen_5.c
 *
 *  Created on: 9 de jun. de 2026
 *      Author: amtuo
 */

/**
 ******************************************************************************
 * @file    screen_config.c
 * @brief   Tela de configuração
 ******************************************************************************
 */

#include "screen_5.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"

/*------------------------------------------------------------------
 * IDs dos itens
 *-----------------------------------------------------------------*/
enum
{
	SCREEN5_C3X,
	SCREEN5_C3Y ,
	SCREEN5_C3Z,
	SCREEN5_BACK
};

/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen5_menu[] =
{
    { "C3X"   , SCREEN5_C3X },
    { "C3Y"   , SCREEN5_C3Y },
    { "C3Z" , SCREEN5_C3Z },
    { "Voltar" , SCREEN5_BACK }
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
    EncoderEvent_t ev;

    ev = encoder_get_event();

    switch(ev)
    {
        case ENC_CW:

            if(selected < (SCREEN5_COUNT - 1))
            {
                uint8_t old = selected;

                selected++;

                menu_widget_update(screen5_menu,old,selected);
            }
            break;

        case ENC_CCW:

            if(selected > 0)
            {
                uint8_t old = selected;

                selected--;

                menu_widget_update(screen5_menu,old,selected);
            }
            break;

        case ENC_PRESS:

            switch(screen5_menu[selected].id)
            {
                case SCREEN5_C3X:

                    /* abrir tela brilho */
                    break;

                case SCREEN5_C3Y:

                    /* abrir tela contraste */
                    break;

                case SCREEN5_C3Z:

                    /* executar reset */
                    break;

                case SCREEN5_BACK:

                    menu_change(SCREEN_4);
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }
}

