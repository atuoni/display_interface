/**
 ******************************************************************************
 * @file    screen_config.c
 * @brief   Tela de configuração
 ******************************************************************************
 */

#include "screen_3.h"

#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"

/*------------------------------------------------------------------
 * IDs dos itens
 *-----------------------------------------------------------------*/
enum
{
    SCREEN3_B1,
	SCREEN3_B2,
	SCREEN3_B3,
	SCREEN3_BACK
};

/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen3_menu[] =
{
    { "B1"   , SCREEN3_B1 },
    { "B2"   , SCREEN3_B2 },
    { "B3" , SCREEN3_B3 },
    { "Voltar", SCREEN3_BACK}
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
    EncoderEvent_t ev;

    ev = encoder_get_event();

    switch(ev)
    {
        case ENC_CW:

            if(selected < (SCREEN3_COUNT - 1))
            {
                uint8_t old = selected;
                selected++;
                menu_widget_update(screen3_menu,old,selected);
            }
            break;

        case ENC_CCW:

            if(selected > 0)
            {
                uint8_t old = selected;

                selected--;

                menu_widget_update(screen3_menu,old,selected);
            }
            break;

        case ENC_PRESS:

            switch(screen3_menu[selected].id)
            {
                case SCREEN3_B1:

                    /* abrir tela brilho */
                    break;

                case SCREEN3_B2:

                    /* abrir tela contraste */
                    break;

                case SCREEN3_B3:

                    /* executar reset */
                    break;

                case SCREEN3_BACK:

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
