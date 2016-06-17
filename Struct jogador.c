// testes de movimento para jogo
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Tamanho da tela
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct PLAYER
{
	int velocidade;
	// Largura total (largura da imagem inteira do jogador)
	int fullW;
	// Largura e altura dos frames do jogador
	int frameW;
	int frameH;
	// Definindo um rect
	SDL_Rect frame, posicao;

	SDL_Surface* Loading_Surf;

}jogador;
// Evento de jogo rodando para loop
int jogoRodando = 1;

int main(int argc, char **argv)
{
	//
	// **********************
	// Inicializacao do SDL | Inicio
	// **********************
	//
	struct jogador;

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
	// Inicializacao do SDL | Fim
	// Definindo um plano de fundo | Inicio

	// Variavel que vai carregar a imagem de fundo
	SDL_Surface* Loading_Surf_Fundo = NULL;

	// Variavel que vai conter o plano de fundo
	SDL_Texture* gFundo = NULL;

	// Carregando plano de fundo na memoria
	Loading_Surf_Fundo = IMG_Load("pokemonuniverse.jpg");

	// Carregando imagem na tela
	gFundo = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf_Fundo);

	// Limpando imagem da memoria
	SDL_FreeSurface(Loading_Surf_Fundo);
	// Definindo um plano de fundo | Fim
	// Variaveis do personagem | Inicio

	// Velocidade de movimento
	float velx = 5.0;
	float vely = 5.0;

	// Largura total (largura da imagem inteira do jogador)
	jogador.fullW = 424;

	// Largura e altura dos frames do jogador
	jogador.frameW = 64;
	jogador.frameH = 64;

	// Definindo um rect

	// Rect para representar o frame
	jogador.frame.x = 0;
	jogador.frame.y = 512;
	jogador.frame.w = jogador.frameW;
	jogador.frame.h = jogador.frameH;

	// Rect para representar a posicao do jogador na tela
	jogador.posicao.x = SCREEN_WIDTH/2 +40;
	jogador.posicao.y = SCREEN_HEIGHT/2;
	jogador.posicao.w = jogador.frameW;
	jogador.posicao.h = jogador.frameH;

	// Variavel que vai carregar a imagem do jogador
	SDL_Surface* Loading_Surf_jogador = NULL;

	// Carregando imagem na memoria
	Loading_Surf_jogador = IMG_Load("Mage w.png");

	// Variavel que vai mostrar a imagem do jogador
	SDL_Texture* gJogador = NULL;

	// Carregando iagem do jogador na tela
	gJogador = SDL_CreateTextureFromSurface(renderer,
		Loading_Surf_jogador);

	// Limpando memoria
	SDL_FreeSurface(Loading_Surf_jogador);

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
					
					jogador.frame.y = 512;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.y > 0 && jogador.posicao.x > 0){
					jogador.posicao.y -= vely;
					jogador.posicao.x -= velx;}
				}
				else if (cima_pressionado && direita_pressionado)
				{
					jogador.frame.y = 512;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.y > 0 && jogador.posicao.x < SCREEN_WIDTH - jogador.frameW){
					jogador.posicao.y -= vely;
					jogador.posicao.x += velx;}
				}
				else if (baixo_pressionado && esquerda_pressionado)
				{
					jogador.frame.y = 640;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.y < SCREEN_HEIGHT - jogador.frameH && jogador.posicao.x > 0){
					jogador.posicao.y += vely;
					jogador.posicao.x -= velx;}
				}
				else if (baixo_pressionado && direita_pressionado)
				{
					jogador.frame.y = 640;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.y < SCREEN_HEIGHT - jogador.frameH && jogador.posicao.x < SCREEN_WIDTH - jogador.frameW){
					jogador.posicao.y += vely;
					jogador.posicao.x += velx;}
				}

				//Principais
				else if (cima_pressionado)
				{
					jogador.frame.y = 512;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.y > 0){
					jogador.posicao.y -= vely;}
				}
				else if (baixo_pressionado)
				{
					jogador.frame.y = 640;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.y < SCREEN_HEIGHT - jogador.frameH){
					jogador.posicao.y += vely;}
				}
				else if (esquerda_pressionado)
				{
					jogador.frame.y = 576;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.x > 0){
					jogador.posicao.x -= velx;}
				}
				else if (direita_pressionado)
				{
					jogador.frame.y = 704;
					if(jogador.frame.x < 512)
					{
						jogador.frame.x = jogador.frame.x + 64;
					}
					else{jogador.frame.x = 0;}
					if(jogador.posicao.x < SCREEN_WIDTH - jogador.frameW){
					jogador.posicao.x += velx;}
				}
				
			}
		}

		// Limpando tela anterior
		SDL_RenderClear(renderer);

		// Renderizando plano de fundo
		SDL_RenderCopy(renderer, gFundo, NULL, NULL);

		// Renderizando o jogador
		SDL_RenderCopy(renderer, gJogador, &jogador.frame, &jogador.posicao);

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