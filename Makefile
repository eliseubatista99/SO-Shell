#A Simple Example Makefile for soshell
# 
# Alvo: Dependencias
# tab Action 1
# tab Action 2
#
#Variaveis: Compiler, compiler flags, libraries to link, name of of object files
#
CC=cc
FLAGS=-c -Wall
LIBS=-lm -lpthread
OBS=main.o execute.o parse.o redirects.o socp.o calc.o isjpg.o blackjack.o tictactoe.o aviso.o help.o
 
#Alvo por defeito é o primeiro 
all :  soshell
 
main.o : shell.h main.c
	$(CC) $(FLAGS) main.c
execute.o : shell.h execute.c
	$(CC) $(FLAGS) execute.c
parse.o : shell.h parse.c
	$(CC) $(FLAGS) parse.c
redirects.o : shell.h redirects.c
	$(CC) $(FLAGS) redirects.c
socp.o: shell.h socp.c
	$(CC) $(FLAGS) socp.c
calc.o: shell.h calc.c
	$(CC) $(FLAGS) calc.c
isjpg.o: shell.h isjpg.c
	$(CC) $(FLAGS) isjpg.c
blackjack.o: shell.h blackjack.c
	$(CC) $(FLAGS) blackjack.c
tictactoe.o: shell.h tictactoe.c
	$(CC) $(FLAGS) tictactoe.c
aviso.o: shell.h aviso.c
	$(CC) $(FLAGS) aviso.c
help.o: shell.h help.c
	$(CC) $(FLAGS) help.c
soshell : $(OBS)
	$(CC)  -o soshell  $(OBS) $(LIBS)
clean limpar:
	rm -f soshell *.o *~
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha"
