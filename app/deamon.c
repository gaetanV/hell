#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

char *mem ;
FILE* fp;
int shmid ;

int memory(int size, int cle){
  int shmid ;
  key_t clef = (key_t) cle;
  shmid = shmget(clef, size, 0666 | IPC_CREAT);

  if ( shmid== -1 ) {
    perror("ERROR start") ;
    exit(1) ; 
  }
  return shmid ;
}

void quit() {
  fclose(fp);
  shmctl(shmid,IPC_RMID,NULL) ;
  exit(0);
}

void ping(){
   printf("%s\n", mem);
}


int main(int argc, char* argv[])
{
    
  
    pid_t process_id;
    pid_t sid = 0;
    
    signal(SIGQUIT, quit);
    signal(SIGINT, ping);
    
    shmid = memory(100,404) ;
    mem = shmat(shmid,0,0) ;

    if (mem ==(char*)-1){
        perror("ERROR") ;
        exit(1) ;
    }

    strcpy(mem,"DEAMON START\n");

    process_id = fork();
      if (process_id < 0)
    {
      printf("fork failed!\n");
      exit(1);
    }

    if (process_id > 0)
    {
      printf("%d,%d\n", shmid, process_id);
      exit(0);
    }

    sid = setsid();
    if(sid < 0)
    {
      exit(1);
    }
   
    FILE* fp = fopen ("memory.txt", "w+");

    while (1)
    {
      sleep(1);
      fprintf(fp, mem);
      fflush(fp);
    }
    fclose(fp);
    return (0);
  
}
 