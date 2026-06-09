#include "menu_widget.h"
#include "tft.h"
#include "gfx.h"
#include "fonts.h"

#define MENU_X          20
#define MENU_Y_START    60
#define MENU_SPACING    30

#define ITEM_WIDTH      220
#define ITEM_HEIGHT     22

/*----------------------------------------------------------
 * Desenha um item
 *---------------------------------------------------------*/
static void draw_item(uint8_t idx, const char *text, uint8_t selected)
{
    uint16_t y;

    y = MENU_Y_START + (idx * MENU_SPACING);

    if(selected)
    {
        tft_fillRect(10,y - 14,ITEM_WIDTH,ITEM_HEIGHT,BLUE);

        GFX_PRINT(MENU_X,y,YELLOW,text);
    }
    else
    {
        tft_fillRect(10,y - 14,ITEM_WIDTH,ITEM_HEIGHT,BLACK);

        GFX_PRINT(MENU_X,y,WHITE,text);
    }
}

/*----------------------------------------------------------
 * Desenha menu completo
 *---------------------------------------------------------*/
void menu_widget_draw(const char *title,const MenuItem_t *items,uint8_t count,uint8_t selected)
{
    uint8_t i;

    tft_fillScreen(BLACK);
    tft_setFont(&mono12x7);
    GFX_PRINT(20,20,GREEN,title);
    GFX_PRINT(10,25,GREEN,"_______________");

    for(i=0;i<count;i++)
    {
        draw_item(i,items[i].text,(i == selected));
    }
}

/*----------------------------------------------------------
 * Atualiza somente seleção
 *---------------------------------------------------------*/
void menu_widget_update(const MenuItem_t *items,uint8_t old_idx,uint8_t new_idx)
{
    draw_item(old_idx,items[old_idx].text,0);

    draw_item(new_idx,items[new_idx].text,1);
}
