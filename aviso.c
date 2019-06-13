#include "shell.h"

/*
   aviso.c 
*/

void aviso(char *mesg, int tempo)
{
  while (tempo > 0)
  {
    sleep (1);
    tempo--;
  }
  fprintf (stderr, "%s : %s\n", WARNING_TAG, mesg);
}

void aviso_Countdown_iniciar(int tempo)
{
  int cont=0;
  
  while(tempo > 0)
  {
    if(cont==0)
    {
      fprintf(stderr, "%sA Shell vai iniciar em: %d ",WARNING_TAG,tempo);
      sleep(1);
      tempo--;
      cont++;
    }
    else
    {
      fprintf(stderr, "%d ",tempo);
      sleep(1);
      tempo--; 
      cont++; 
    }
  }
}

void aviso_Countdown_encerrar(int tempo)
{
  int cont=0;
  
  while(tempo > 0)
  {
    if(cont==0)
    {
      fprintf(stderr, "%sA Shell vai encerrar em: %d ",WARNING_TAG,tempo);
      sleep(1);
      tempo--;
      cont++;
    }
    else
    {
      fprintf(stderr, "%d ",tempo);
      sleep(1);
      tempo--; 
      cont++; 
    }
  }
}

void *avisoWrapper(void *args)
{
  aviso_t *ptr = (aviso_t *) args;
  aviso(ptr->msg, ptr->tempo);
  free(ptr);
  return NULL;
}