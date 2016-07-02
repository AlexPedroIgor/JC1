// Copyright © 2016 Alex, Pedro e Igor
// Licensed under the MIT/Expat license.

#ifndef COLISAO_H
#define COLISAO_H

// BIBLIOTECAS INTERNAS
#include "main.h"
#include "base.h"
#include "fisica.h"
#include "armas.h"
#include "inimigo.h"

// ******************************************************************************************************************************

//
// FUNCOES
//

int Colisao_Circular(Objeto* objeto1, Objeto* objeto2);
int Colisao_Perimetro(Objeto* objeto1, Objeto* objeto2);
int Colisao_LimiteDeTela(Objeto* objeto);
void Teste_de_Colisao(Inimigos* inimigos, Jogadores* jogadores);
void Teste_de_Impacto_Inimigos(Projeteis* projeteis, Inimigos* inimigos);

// ******************************************************************************************************************************

#endif

// FIM