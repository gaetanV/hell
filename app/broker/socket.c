#ifdef WIN32
#include "socketwindow.c"
#elif defined (linux)
#include "socketlinux.c"
#endif

int main(int argc, char* argv[])
{
    initSocket();
    endSocket();
    return 0;
}
