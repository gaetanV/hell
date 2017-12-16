#include <sys/types.h>

#ifdef WIN32
#include <windows.h>
#elif defined (linux)
#include "brokerlinux.c"
#endif
#include <stdlib.h>
#include <stdio.h>

char *mem ;
int shmPointerId;
int shmStreamId;
int shmGroupsId;

int main(int argc, char* argv[])
{
    pid_t process_id;
    pid_t sid = 0;

#ifdef WIN32
 
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    BOOL rv = FALSE;
    char cmdline[] = TEXT("brokerwindow.exe");

    memset(&si,0,sizeof(si));
    si.cb = sizeof(si);

    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE; 

    memset(&pi,0,sizeof(pi));
    rv = CreateProcess(NULL, cmdline, NULL, NULL,
                           FALSE, CREATE_NEW_CONSOLE,
                           NULL, NULL, &si, &pi);
    return rv ? 0 : 1;

#elif defined (linux)
   brokerlinux();
#endif
 



}
 