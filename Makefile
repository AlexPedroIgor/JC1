# Makefile do jogo ##
# Bibliotecas: SDL 2.0, SDL_image 2.0, SDL_mixer 2.0 ##

## O comando make cria o executavel ##
## O comando make clean limpa os arquivos .o ##
## O comando make mrproper apaga o executavel ##

############################### Makefile ###############################

all: meujogo
meujogo: main.o menu.o jogo.o som.o config.o fisica.o inimigo.o base.o rpg.o animacao.o colisao.o armas.o
		# Compilando o jogo
		gcc -o meujogo som.o jogo.o menu.o config.o main.o fisica.o inimigo.o base.o rpg.o animacao.o colisao.o armas.o -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/meujogo.gccmessages
#------> Execucao dos arquivos
som.o: som.c main.h som.h
		gcc -o som.o -c som.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/som.gccmessages
#
jogo.o: jogo.c main.h base.h som.h config.h fisica.h inimigo.h colisao.h animacao.h rpg.h
		gcc -o jogo.o -c jogo.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/jogo.gccmessages
#
menu.o: menu.c som.h main.h config.h
		gcc -o menu.o -c menu.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/menu.gccmessages
#
config.o: config.c main.h base.h
		gcc -o config.o -c config.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/config.gccmessages
#
inimigo.o: inimigo.c main.h config.h
		gcc -o inimigo.o -c inimigo.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/inimigo.gccmessages
#
fisica.o: fisica.c fisica.h main.h config.h inimigo.h base.h
		gcc -o fisica.o -c fisica.c -Wall -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/fisica.gccmessages
#
base.o: base.c base.h main.h rpg.h config.h
		gcc -o base.o -c base.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/base.gccmessages
#
rpg.o: rpg.c rpg.h main.h
		gcc -o rpg.o -c rpg.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/rpg.gccmessages
#
colisao.o: colisao.c colisao.h main.h base.h
		gcc -o colisao.o -c colisao.c -Wall -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/colisao.gccmessages
#
animacao.o: animacao.c animacao.h main.h base.h
		gcc -o animacao.o -c animacao.c -Wall -lm -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/animacao.gccmessages
#
armas.o: armas.c armas.h main.h base.h
		gcc -o armas.o -c armas.h -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/armas.gccmessages
#
main.o: main.c main.h menu.h jogo.h config.h base.h
		gcc -o main.o -c main.c -Wall -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 2>log/main.gccmessages
#
clean:
		rm -rf *.o
#
mrproper: clean
		rm -rf meujogo
