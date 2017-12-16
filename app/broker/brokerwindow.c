#include <errno.h>
#include <sys/types.h>

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char* argv[])
{
   HANDLE hMapFile;
   LPCTSTR pBuf;

   hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,   
                 NULL,                   
                 PAGE_READWRITE,         
                 0,                      
                 100,                
                 "404");

   if (hMapFile == NULL)
   {
      printf("ERROR");
      return 1;
   }

   getchar();
   CloseHandle(hMapFile);

   return 0;
  

}