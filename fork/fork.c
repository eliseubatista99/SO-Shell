#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
 int main()
 {
    int x=2, pid;
    pid=fork();
    if(0==pid)
    {
        x--;
    }
    else
    {
        execl("/bin/date","date",NULL);
        x=x+2;
    }
    printf("x= %d\n",x);
         
 }