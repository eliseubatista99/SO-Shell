#include "shell.h"

void streamCopy(int in, int out)
{
    int ch;
    char buffer[1];
    while((ch=read(in,buffer,1))>0)
    {
        write(out,buffer,ch);
    }
}

void socp(char *fonte, char *destino)
{
    int fdIn = open(fonte, O_RDWR);
    int fdOut = open(destino, O_WRONLY);
    if (fdIn<0)
    {
        fprintf(stderr, "%sErro a abrir o ficheiro fonte!\n",ERROR_TAG);
        return;
    }

     if (fdOut<0)
    {
        fdOut=creat(destino, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    }
    
    streamCopy(fdIn, fdOut);
    printf("%s%sFicheiro copiado com sucesso%s\n",BOLD,GREEN,NORMAL);
    close(fdIn);
    close(fdOut);
}

void *socpth(void *args)
{
  copiar_t *ptr = (copiar_t *) args;
  socp(ptr->fonte, ptr->destino) ;
  free(ptr);
  return NULL;
}
