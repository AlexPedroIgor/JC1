// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef MAIN_H
#define MAIN_H

// Bibliotaca do SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// Bocliotecas C
#include <stdio.h>
#include <stdlib.h>

// Bicliotecas internas
#include "config.h"
#include "base.h"
#include "menu.h"
#include "jogo.h"

// Condicionais
#define VERDADEIRO				1
#define FALSO					0

// Modos de jogo
#define	MENU			1
#define	SINGLEPAYER		2
#define	MULTIPLAYER		3

// Variaveis utilizadas em todo o jogo
int jogoRodando, estadoDeJogo;

// Nome do Jogo
#define NOME_DO_JOGO "SUPER SMASH ARANHA-MORCEGO"

// Tamanho de Tela
#define SCREEN_WIDTH			800
#define SCREEN_HEIGHT			600

// Framerate do jogo
#define FPS						30

// Funcoes do main
int main (int argc, char **argv);
void ERRO (int erro);

#endif

// fim
