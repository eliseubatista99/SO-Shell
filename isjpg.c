#include "shell.h"

int isjpg(int file)
{
    if (file < 0)
    {
        printf("%sFicheiro %sinexistente%s\n",ERROR_TAG,BOLD,NORMAL);
        return 0;
    }
    unsigned char b[4];
    read(file,b,4);
    lseek(file,0L,0);
    if (b[0]==0xff && b[1]==0xd8 && b[2]==0xff && b[3]==0xe0)
    {
        printf("%sO fciheiro %sé um jpeg%s\n",RESULTADO_TAG,BOLD,NORMAL);
        return 1;
    }
    printf("%sO ficheiro %snão é um jpeg%s\n",RESULTADO_TAG,BOLD,NORMAL);
    return 0;
}