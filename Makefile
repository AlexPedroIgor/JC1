# Makefile do jogo ##
# Bibliotecas: SDL 2.0, SDL_image 2.0, SDL_mixer 2.0 ##

## O comando make cria o executavel ##
## O comando make clean limpa os arquivos .o ##
## O comando make mrproper apaga o executavel ##

############################### Makefile ###############################

all: meujogo
meujogo: main.o base.o config.o rpg.o som.o colisao.o fisica.o inimigo.o animacao.o armas.o creditos.o menu.o jogo.o
		# Compilando o jogo
		gcc -o meujogo base.o som.o jogo.o menu.o config.o main.o fisica.o inimigo.o rpg.o animacao.o colisao.o armas.o -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/meujogo.gccmessages
#------> Execucao dos arquivos
#
main.o: main.c main.h base.h menu.h jogo.h config.h
		gcc -o main.o -c main.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/main.gccmessages
#
base.o: base.c base.h main.h rpg.h
		gcc -o base.o -c base.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/base.gccmessages
#
config.o: config.c config.h base.h
		gcc -o config.o -c config.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/config.gccmessages
#
rpg.o: rpg.c rpg.h
		gcc -o rpg.o -c rpg.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/rpg.gccmessages
#
som.o: som.c som.h
		gcc -o som.o -c som.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/som.gccmessages
#
colisao.o: colisao.c colisao.h main.h base.h
		gcc -o colisao.o -c colisao.c -Wall -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/colisao.gccmessages
#
fisica.o: fisica.c fisica.h main.h config.h inimigo.h base.h
		gcc -o fisica.o -c fisica.c -Wall -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/fisica.gccmessages
#
inimigo.o: inimigo.c main.h config.h base.h
		gcc -o inimigo.o -c inimigo.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/inimigo.gccmessages
#
animacao.o: animacao.c animacao.h base.h config.h
		gcc -o animacao.o -c animacao.c -Wall -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/animacao.gccmessages
#
armas.o: armas.c armas.h base.h config.h
		gcc -o armas.o -c armas.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/armas.gccmessages
#
creditos.o: creditos.c creditos.h base.h config.h
		gcc -o creditos.o -c creditos.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/creditos.gccmessages
#
menu.o: menu.c som.h main.h config.h base.h
		gcc -o menu.o -c menu.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/menu.gccmessages
#
jogo.o: jogo.c main.h base.h som.h config.h fisica.h inimigo.h colisao.h animacao.h rpg.h
		gcc -o jogo.o -c jogo.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/jogo.gccmessages
#
clean:
		rm -rf *.o
#
mrproper: clean
		rm -rf meujogo
