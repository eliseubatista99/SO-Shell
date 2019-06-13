/*
   execute . cria um processo prog�nito e executa um programa
*/
#include "shell.h"

int ultimo (int numargs, char **args)
{
  if (args[numargs-1][0]=='&')
  {
    args[numargs-1]=NULL;
    return BG;
  }
  return FG;
}

int containsPipe(int numargs, char **args)
{
  int index;
  for(index=0;index<numargs;index++)
  {
    if(args[index][0]=='|')
    {
      return index;
    }
  }
  return -1;
}

void execute (int numargs, char **args)
{
  int indice, pid, pidFilho=0, status,fd[2];
  indice = containsPipe(numargs, args);
  int code = ultimo(numargs, args);
  

  if(code == BG)
  {
    numargs--;
  
  }
  if ((pid = fork ()) < 0)
    {				/* cria um processo progenito */
      perror ("forks");		/* NOTE: perror() produz uma pequema mensagem
				 * de erro para o stream */
      exit (1);			/* estandardizado de erros que descreve o
				 * ultimo erro encontrado */
      /* durante uma chamada ao sistema ou funcao duma biblioteca */
    }
  if (pid == 0)
    {
      redirects(args,numargs);
      if(indice>0)
      {
        args[indice] = NULL;
        numargs  = numargs-1;
        pipe(fd);
        pidFilho = fork();

        if(pidFilho==0)
        {
          //write
          numargs = indice;
          dup2(fd[1],STDOUT_FILENO);
          close(fd[0]);
          execvp(*args,args);
        }
        else
        {
          //read
          args=args+indice+1;
          numargs=numargs-indice-1;
          dup2(fd[0],STDIN_FILENO);
          close(fd[1]);
          execvp(*args,args);
        }
        
      }
      else
      {
          execvp (*args, args);	/* NOTE: as versoes execv() e
				 * execvp() de execl() sao uteis
				 * quando */
      }
      perror (*args);		/* o numero de argumentos nao e. conhecido.
				 * Os argumentos de  */
      exit (1);			/* execv() e execvp() sao o nome do ficheiro
				 * a ser executado e um */
    }				/* vector de strings que contem os
				 * argumentos. O ultimo argument */

  if(code == FG)
  {
    while(wait(&status) != pid);
  }
  
  return;
}
