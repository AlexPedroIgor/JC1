//
// ********************
// testes de movimento para jogo
// ********************
//
//
//


#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Tamanho da tela
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Evento de jogo rodando para loop
int jogoRodando = 1;

int main(int argc, char **argv)
{
	//
	// **********************
	// Inicializacao do SDL | Inicio
	// **********************
	//

	// Inicia video
	SDL_Init (SDL_INIT_VIDEO);

	// Variavel que vai representar a janela
	SDL_Window* window = NULL;

	// Criando a janela
	window = SDL_CreateWindow("Teste de Movimento",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	// Variavel que vai representar o render
	SDL_Renderer* renderer = NULL;

	//Inicianco o render
	renderer = SDL_CreateRenderer(window, -1, 0);

	//
	// **********************
	// Inicializacao do SDL | Fim
	// **********************
	//

	//
	// *****************************
	// Definindo um plano de fundo | Inicio
	// *****************************
	//

	// Variavel que vai carregar a imagem de fundo
	SDL_Surface* Loading_Surf_Fundo = NULL;

	// Variavel que vai conter o plano de fundo
	SDL_Texture* gFundo = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf_Fundo = IMG_Load("arte/fundo/fundo.jpg");

	// Carregando imagem na tela
	gFundo = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf_Fundo);

	// Limpando imagem da memoria
	SDL_FreeSurface(Loading_Surf_Fundo);

	//
	// *****************************
	// Definindo um plano de fundo | Fim
	// *****************************
	//

	//
	// *************************
	// Variaveis do personagem | Inicio
	// *************************
	//

	// Velocidade de movimento
	float velx = 2.5;
	float vely = 2.5;

	// Largura total (largura da imagem inteira do jogador)
	int jogador_fullW = 424;

	// Largura e altura dos frames do jogador
	int jogador_frameW = 53;
	int jogador_frameH = 53;

	// Definindo um rect
	SDL_Rect jogador_frame, jogador_posicao;

	// Rect para representar o frame
	jogador_frame.x = 0;
	jogador_frame.y = 0;
	jogador_frame.w = jogador_frameW;
	jogador_frame.h = jogador_frameH;

	// Rect para representar a posicao do jogador na tela
	jogador_posicao.x = SCREEN_WIDTH/2;
	jogador_posicao.y = SCREEN_HEIGHT/2;
	jogador_posicao.w = jogador_frameW;
	jogador_posicao.h = jogador_frameH;

	// Variavel que vai carregar a imagem do jogador
	SDL_Surface* Loading_Surf_Jogador = NULL;

	// Carregando imagem na memoria
	Loading_Surf_Jogador = IMG_Load("arte/personagens/jogador1/jogador1.png");

	// Variavel que vai mostrar a imagem do jogador
	SDL_Texture* gJogador = NULL;

	// Carregando iagem do jogador na tela
	gJogador = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf_Jogador);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf_Jogador);

	//
	// *************************
	// Variaveis do personagem | Fim
	// *************************
	//

	//
	// **********************
	// Loop do jogo rodando | Inicio
	// **********************
	//

	// Inicializando eventos
	SDL_Event event;

	while (jogoRodando)
	{
		// Verificando se ha eventos
		if (SDL_PollEvent (&event))
		{
			// Caso o evento seja sair, finaliza o jogo
			if (event.type == SDL_QUIT)
				jogoRodando = 0;

			// Verificando se houve um evendo de tecla pressionada
			if (event.type == SDL_KEYDOWN)
			{
				/*
				// Movimentando o jogador
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						jogador_frame.x = 0;
						jogador_posicao.y -= vely;
						break;
					case SDLK_DOWN:
						jogador_frame.x = 212;
						jogador_posicao.y += vely;
						break;
					case SDLK_LEFT:
						jogador_frame.x = 106;
						jogador_posicao.x -= velx;
						break;
					case SDLK_RIGHT:
						jogador_frame.x = 318;
						jogador_posicao.x += velx;
						break;
				}*/

				//
				//*************************
				// Outro tipo de movimento| Inicio
				//*************************
				//

				// Declarando uma variavel para teclado
				const Uint8 *keystates = SDL_GetKeyboardState(NULL);

				// Definindo teclas
				int cima_pressionado = keystates[SDL_SCANCODE_UP];
				int baixo_pressionado = keystates[SDL_SCANCODE_DOWN];
				int esquerda_pressionado = keystates[SDL_SCANCODE_LEFT];
				int direita_pressionado = keystates[SDL_SCANCODE_RIGHT];

				// Executando movimentacoes

				// Diagonais
				if (cima_pressionado && esquerda_pressionado)
				{
					jogador_frame.x = 53;
					jogador_posicao.y -= vely;
					jogador_posicao.x -= velx;
				}
				else if (cima_pressionado && direita_pressionado)
				{
					jogador_frame.x = 371;
					jogador_posicao.y -= vely;
					jogador_posicao.x += velx;
				}
				else if (baixo_pressionado && esquerda_pressionado)
				{
					jogador_frame.x = 159;
					jogador_posicao.y += vely;
					jogador_posicao.x -= velx;
				}
				else if (baixo_pressionado && direita_pressionado)
				{
					jogador_frame.x = 265;
					jogador_posicao.y += vely;
					jogador_posicao.x += velx;
				}

				//Principais
				else if (cima_pressionado)
				{
					jogador_frame.x = 0;
					jogador_posicao.y -= vely;
				}
				else if (baixo_pressionado)
				{
					jogador_frame.x = 212;
					jogador_posicao.y += vely;
				}
				else if (esquerda_pressionado)
				{
					jogador_frame.x = 106;
					jogador_posicao.x -= velx;
				}
				else if (direita_pressionado)
				{
					jogador_frame.x = 318;
					jogador_posicao.x += velx;
				}
				//
				//*************************
				// Outro tipo de movimento| Fim
				//*************************
				//
			}
		}

		// Limpando tela anterior
		SDL_RenderClear(renderer);

		// Renderizando plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderizando o jogador
		SDL_RenderCopy(renderer, gJogador, &jogador_frame, &jogador_posicao);

		// Atualizando nova tela
		SDL_RenderPresent(renderer);

		// Esperar por 1 segundo(s)
		//SDL_Delay(15);
	}

	//
	// **********************
	// Loop do jogo rodando | Fim
	// **********************
	//

	SDL_DestroyTexture(gFundo);
	SDL_DestroyTexture(gJogador);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}