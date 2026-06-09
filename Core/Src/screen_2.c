/**
 ******************************************************************************
 * @file    screen_config.c
 * @brief   Tela de configuração
 ******************************************************************************
 */

#include "screen_2.h"

#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"

/*------------------------------------------------------------------
 * IDs dos itens
 *-----------------------------------------------------------------*/
enum
{
    SCREEN2_A1,
    SCREEN2_A2,
    SCREEN2_A3,
    SCREEN2_BACK
};

/*------------------------------------------------------------------
 * Tabela do menu
 *-----------------------------------------------------------------*/
static const MenuItem_t screen2_menu[] =
{
    { "A1"   , SCREEN2_A1},
    { "A2"   , SCREEN2_A2},
    { "A3" , SCREEN2_A3},
    { "Voltar", SCREEN2_BACK}
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
    EncoderEvent_t ev;

    ev = encoder_get_event();

    switch(ev)
    {
        case ENC_CW:

            if(selected < (SCREEN2_COUNT - 1))
            {
                uint8_t old = selected;

                selected++;

                menu_widget_update(screen2_menu,old,selected);
            }
            break;

        case ENC_CCW:

            if(selected > 0)
            {
                uint8_t old = selected;

                selected--;

                menu_widget_update(screen2_menu,old,selected);
            }
            break;

        case ENC_PRESS:

            switch(screen2_menu[selected].id)
            {
                case SCREEN2_A1:

                    /* abrir tela brilho */
                    break;

                case SCREEN2_A2:

                    /* abrir tela contraste */
                    break;

                case SCREEN2_A3:

                    /* executar reset */
                    break;

                case SCREEN2_BACK:

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
