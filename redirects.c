#include "shell.h"

//redirects are handled in reverse order
//2> >>> <

#define FILE_MODE (S_IRUSR | S_IWUSR)

int redirects(char *args[],int numargs)
{
    //redirect stdout >
    if (numargs<3)
    {
        return 0;
    }
    //tratar do >
    if (strcmp(args[numargs-2],"2>")==0)
    {
        int fd=creat (args[numargs-1],FILE_MODE | S_IRGRP | S_IROTH);
        if(fd<0)
        {
            return -1; //indica um erro
        }
        dup2(fd,STDOUT_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }
    else if((strcmp(args[numargs-2],">")==0) || (strcmp(args[numargs-2], ">>")))
    {
        int fd = creat(args[numargs-1],FILE_MODE | S_IRGRP | S_IROTH);
        if(fd < 0)
        {
            return -1;
        }
        dup2(fd, STDERR_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }
    else if(strcmp(args[numargs-2],"<")==0)
    {
        int fd = open(args[numargs-1],O_RDONLY);
        if(fd < 0)
        {
            return -1;
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }
    else
    {
        printf("%sSímbolo não reconhecido\n",ERROR_TAG);
    }
    
    return numargs;
    


}