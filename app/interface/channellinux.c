#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mem ;

int token(int num)
{
    mem = shmat(num,0,0) ;
    if (mem ==(char*)-1){
        perror("NO MATCH") ;
        exit(1) ;
    }
    return 1;
}

int set(char *buffer){
   strncpy(mem, buffer, 100);
   return 1;
}

int get(char *buffer){
   strncpy(buffer, mem, 100);
   return 1;
}