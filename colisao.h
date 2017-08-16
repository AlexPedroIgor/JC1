// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef COLISAO_H
#define COLISAO_H

// BIBLIOTECAS DO SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// BIBLIOTECAS INTERNAS
#include "base.h"
#include "config.h"

// ******************************************************************************************************************************

//
// FUNCOES
//

int Colisao_Circular(Objeto*, Objeto*);
int Colisao_Circular2(Objeto*, Objeto*);
int Colisao_Perimetro(Objeto*, Objeto*);
int Colisao_Perimetro2(Objeto*, Objeto*);
int Colisao_LimiteDeTela(Objeto*);
int Colisao_LimiteDeTela2(Objeto*);
void Teste_de_Colisao(Inimigos*, Jogadores*);
void Teste_de_Impacto_Inimigos(SDL_Renderer*, Projeteis*, Inimigos*);


// ******************************************************************************************************************************

#endif

// FIM
