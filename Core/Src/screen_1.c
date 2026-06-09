#include "screen_1.h"
#include "menu.h"
#include "encoder.h"
#include "menu_widget.h"

/*------------------------------------------------------------------
 * IDs locais
 *-----------------------------------------------------------------*/
enum
{
    SCREEN1_A,
    SCREEN1_B,
    SCREEN1_C
};

/*------------------------------------------------------------------
 * Tabela
 *-----------------------------------------------------------------*/
static const MenuItem_t screen1_menu[] =
{
    { "A", SCREEN1_A  },
    { "B" , SCREEN1_B },
    { "C" , SCREEN1_C }
};

#define SCREEN1_COUNT (sizeof(screen1_menu)/sizeof(screen1_menu[0]))

static uint8_t selected = 0;

/*------------------------------------------------------------------
 * Protótipos
 *-----------------------------------------------------------------*/
static void screen1_draw(void);
static void screen1_event(void);

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
    EncoderEvent_t ev;

    ev = encoder_get_event();

    switch(ev)
    {
        case ENC_CW:

            if(selected < (SCREEN1_COUNT - 1))
            {
                uint8_t old = selected;
                selected++;
                menu_widget_update(screen1_menu,old,selected);
            }
            break;

        case ENC_CCW:

            if(selected > 0)
            {
                uint8_t old = selected;

                selected--;

                menu_widget_update(screen1_menu,old,selected);
            }
            break;

        case ENC_PRESS:

            switch(screen1_menu[selected].id)
            {
                case SCREEN1_A:
                    menu_change(SCREEN_2);
                    break;

                case SCREEN1_B:
                    menu_change(SCREEN_3);
                    break;

                case SCREEN1_C:
                    menu_change(SCREEN_4);
                    break;
            }
            break;

        default:
            break;
    }
}
