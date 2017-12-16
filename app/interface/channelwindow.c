#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int get(char *buffer){

  HANDLE hMapFile = OpenFileMapping(
                PAGE_READWRITE,   
                FALSE,               
                "404");               
  LPCTSTR pBuf;
  pBuf =  MapViewOfFile(hMapFile, 
               PAGE_READWRITE, 
               0,
               0,
               100);
  char resp[100];
  sprintf(resp,"I think that %s!\n", pBuf);

  strncpy(buffer,resp, 100);
  
  UnmapViewOfFile(pBuf);  
  return 1;
}
