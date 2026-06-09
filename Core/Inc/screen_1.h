/**
 ******************************************************************************
 * @file    screen_1.h
 * @brief   Tela principal da aplicação
 ******************************************************************************
 */

#ifndef SCREEN_1_H
#define SCREEN_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "screen.h"

/*----------------------------------------------------------
 * Objeto da tela HOME
 *---------------------------------------------------------*/
extern Screen_t screen_1;

/*----------------------------------------------------------
 * Inicialização da tela HOME
 *---------------------------------------------------------*/
void screen1_init(void);

#ifdef __cplusplus
}
#endif

#endif /* SCREEN_HOME_H */
