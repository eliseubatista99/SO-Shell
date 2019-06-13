#include "shell.h"

char prompt[100];


int main (int argc, char *argv[])
{
  int numargs;
  int len;
  char linha[1024];		/* um comando */
  char *args[64];		/* com um maximo de 64 argumentos */

  strcpy (prompt, "SOSHELL:> ");
  aviso_Countdown_iniciar(3);
  printf("\n");
  while (1)
    {
      printf ("%s%s%s",BOLD,prompt,NORMAL);
      if (fgets (linha, 1023, stdin) == NULL)
	{
	  printf ("\n");
	  exit (0);
	}
      len = strlen (linha);
      if (1 == len)
	continue;		/* linha é apenas \n */
      if (linha[len - 1] == '\n')
	linha[len - 1] = '\0';

      numargs = parse (linha, args);	/* particiona a string em argumentos */

      if (!builtin (numargs, args))
	execute (numargs, args);		/* executa o comando */
    }
  return 0;
}

int builtin (int numargs, char *args[])
{
  if (strcmp (args[0], "sair") == 0 || strcmp (args[0], "quit") == 0 || strcmp (args[0], "exit") == 0 || strcmp (args[0], "leave") == 0)
  {
    int time;
    if(args[1]!=NULL)
    {
      time = atoi(args[1]);
    }
    else
    {
      time=3;
    }
    aviso_Countdown_encerrar(time);
    exit (0);
    return 1;
  }

  if((strlen(args[0])>4)&& 0==strncmp(args[0],"PS1=",4))
  {
    strcpy(prompt,args[0]+4);
    return 1; //comando embutido
  }

  if (strncmp (args[0], "42", 2) == 0)
  {
    printf ("%s%s4%s2 %si%ss %st%sh%se %sa%sn%ss%sw%se%sr %st%so %sl%si%sf%se %st%sh%se %su%sn%si%sv%se%sr%ss%se %sa%sn%sd %se%sv%se%sr%sy%st%sh%si%sn%sg%s\n",BOLD,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,MAGENTA,CYAN,BLUE,NORMAL);
    return 1;			/* funcionalidade embutida */
  }

  if(0==strcmp(args[0],"quemsoueu"))
  {
    system("id");
    return 1; //comando embutido
  }

  if(0==strcmp(args[0],"socp"))
  {
    if(numargs < 3)
    {
      fprintf(stderr, "%s Numero de argumentos inferior a 3!\n", ERROR_TAG);
      return 1;
    }
    socp(args[1],args[2]);
    return 1; //comando embutido
  }

  if(0 == strcmp(args[0], "socpth"))
  {
    if(numargs < 3)
    {
      fprintf(stderr, "%s ONumero de argumentos inferior a 3!\n", ERROR_TAG);
      return 1;
    }
    pthread_t th;
    copiar_t * ptr = (copiar_t *) malloc(sizeof(copiar_t));
    strcpy(ptr->fonte, args[1]);
    strcpy(ptr->destino, args[2]);
    pthread_create(&th, NULL, socpth, (void *)ptr);
    return 1;
}

  if(0==strcmp(args[0],"calc"))
  {
    if (numargs<4){
      printf("%sFaltam argumentos!\n",ERROR_TAG);
    }
    else{
    calc(args[1],args[2],args[3]);
    }
    return 1; //comando embutido
  }

  if(0==strcmp(args[0],"bits"))
  {
    if (numargs<4){
      printf("%sFaltam argumentos!\n",ERROR_TAG);
    }
    else{
    bits(args[1],args[2],args[3]);
    }
    return 1; //comando embutido
  }

  if(0==strcmp(args[0],"obterinfo"))
  {
    printf("SOSHELL 2018 versão 1.0\n");
    return 1; //comando embutido
  }

  if((0==strcmp(args[0],"isjpg")) || (0==strcmp(args[0],"isjpeg")))
  {
    if (numargs<2){
      printf("%sFaltam argumentos!\n",ERROR_TAG);
    }
    else{
    int file=open(args[1],O_RDONLY);
    isjpg(file);
    }
    return 1; //comando embutido
  }

  if(0==strcmp(args[0],"cd"))
  {
    int err;
    if ((NULL == args[1]) || (0 == strcmp(args[1],"~")))
      err=chdir(getenv("HOME"));
    else
      err=chdir(args[1]);
    if (err<0)
      perror("chdir failed");
    return 1; //comando embutido
  }

  if(0==strcmp(args[0],"blackjack"))
  {
    blackjack();
    return 1; //comando embutido
  }

  if(0==strcmp(args[0],"tictactoe"))
  {
    tictactoe();
    return 1; //comando embutido
  }
  //Para usar o aviso sem threads, alterar o "aviso" desta função para "avisoth"
  if(0 == strcmp(args[0], "avisoth"))
  {
    if(numargs < 3)
    {
      fprintf(stderr, "%s O número de argumentos é menor que 3!\n", ERROR_TAG);
      return 1;
    }
    pthread_t th;
    aviso_t * ptr = (aviso_t *) malloc(sizeof(aviso_t));
    strcpy(ptr->msg, args[1]);
    ptr->tempo=atoi(args[2]);
    pthread_create(&th, NULL, avisoWrapper, (void *)ptr);
    return 1;
  }

  if(0==strcmp(args[0], "aviso"))
  {
      if(numargs < 3)
      {
        fprintf(stderr, "%s O número de argumentos é menor que 3!\n", ERROR_TAG);
        return 1;
      }

      aviso(args[1], atoi(args[2]));
      return 1;
  }

  if(0==strcmp(args[0], "help"))
  {
      help();
      return 1;
  }

/*
  if (strcmp (args[0], "qualquercoisa") == 0)
    {
       funcinalidade
       return 1;
    }

   if ( strcmp(args[0],"socp")==0) { socp(..,..) open/creat/read/write ; return 1; }
*/

//devolver 0 indique que n�o h� comnando embutido

  return 0;
}
