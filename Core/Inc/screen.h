#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

typedef struct
{
    void (*draw)(void);
    void (*event)(void);

}Screen_t;

typedef enum
{
    SCREEN_1 = 0,
    SCREEN_2,
    SCREEN_3,
	SCREEN_4,
	SCREEN_5,

    SCREEN_COUNT

}ScreenId_t;

/* tabela global de telas */
extern Screen_t *screen_table[SCREEN_COUNT];

void screen_init(void);

#endif
