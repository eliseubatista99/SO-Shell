#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <dirent.h>

typedef struct
{
  char msg[100];
  int tempo;
}aviso_t;

typedef struct
{
  char fonte[100];
  char destino[100];
}copiar_t;

//Funções default
int parse(char *buf, char **args);
void execute(int numargs, char **args);

//Ficheiro: main.c
int builtin (int numargs, char *args[]);

//Ficheiro: socp.c
void socp(char *fonte, char *destino);
void *socpth(void *args);

//Ficheiro: calc.c
void calc(char *operando1, char *operacao, char *operando2);
void bits(char *operando1, char *operacao, char *operando2);

//Ficheiro: isjpg.c
int isjpg(int file);

//Ficheiro: redirects.c
int redirects(char *args[],int numargs);

//Ficheiro: blackjack.c
void blackjack();

//Ficheiro: tictactoe.c
void tictactoe();

//Ficheiro: aviso.c
void aviso(char *mensagem,int tempo);
void aviso_Countdown_iniciar(int tempo);
void aviso_Countdown_encerrar(int tempo);
void *avisoWrapper(void *args);

//Ficheiro: help.c
void help();

//Fontes
#define NORMAL "\x1B[0m"
#define BOLD "\x1B[1m"

//Cores
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE "\x1B[37m"

//Tags
#define DEFAULT_TAG "\x1B[32m\x1B[1m[SHELL]>  \x1B[0m"
#define HELP_TAG "\x1B[36m\x1B[1m[HELP]>  \x1B[0m"
#define INFO_TAG "\x1B[34m\x1B[1m[INFO]>  \x1B[0m"
#define ERROR_TAG "\x1B[31m\x1B[1m[ERRO]>  \x1B[0m"
#define WARNING_TAG "\x1B[33m\x1B[1m[AVISO]>  \x1B[0m"
#define RESULTADO_TAG "\x1B[34m\x1B[1m[RESULTADO]>  \x1B[0m"

/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
