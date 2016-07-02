// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef MAIN_H
#define MAIN_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS DO C
#include <stdio.h>
#include <stdlib.h>

// BIBLIOTECAS INTERNAS
#include "config.h"
#include "base.h"
#include "menu.h"
#include "jogo.h"

// ******************************************************************

//
// CONSTANTES
//

// CONDICIONAIS
#define VERDADEIRO		1
#define FALSO			0

// MODOS DE JOGO
#define	MENU			1
#define	JOGO			2

// NOME DO JOGO
#define NOME_DO_JOGO "SUPER SMASH ARANHA-MORCEGO"

// TAMANHO DA TELA
#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

// FRAMERATE DO JOGO
#define FPS				30

// *******************************************************************

//
// VARIAVEIS GLOBAIS
//

// VARIAVEIS DE GERENCIAMENTO DO MAIN
int mainRodando, estadoDeJogo;

// ********************************************************************

//
// FUNCOES
//

int main (int argc, char **argv);
void ERRO (int erro);

// ********************************************************************

#endif

// FIM
