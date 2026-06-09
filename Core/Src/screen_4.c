/**
 ******************************************************************************
 * @file    screen_config.c
 * @brief   Tela de configuração
 ******************************************************************************
 */

#include "screen_4.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"

/*------------------------------------------------------------------
 * IDs dos itens
 *-----------------------------------------------------------------*/
enum
{
	SCREEN4_C1,
	SCREEN4_C2,
	SCREEN4_C3,
	SCREEN4_BACK
};

/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen4_menu[] =
{
    { "C1"   , SCREEN4_C1 },
    { "C2"   , SCREEN4_C2 },
    { "C3" , SCREEN4_C3 },
    { "Voltar" , SCREEN4_BACK }
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
    EncoderEvent_t ev;

    ev = encoder_get_event();

    switch(ev)
    {
        case ENC_CW:

            if(selected < (SCREEN4_COUNT - 1))
            {
                uint8_t old = selected;

                selected++;

                menu_widget_update(screen4_menu,old,selected);
            }
            break;

        case ENC_CCW:

            if(selected > 0)
            {
                uint8_t old = selected;

                selected--;

                menu_widget_update(screen4_menu,old,selected);
            }
            break;

        case ENC_PRESS:

            switch(screen4_menu[selected].id)
            {
                case SCREEN4_C1:

                    /* abrir tela brilho */
                    break;

                case SCREEN4_C2:

                    /* abrir tela contraste */
                    break;

                case SCREEN4_C3:

                    /* executar reset */
                	menu_change(SCREEN_5);
                    break;

                case SCREEN4_BACK:

                    menu_change(SCREEN_1);
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }
}
