
import subprocess

sp = subprocess.call('gcc -L$ORIGIN -c socket.c -o socket.o -lwsock32   ')
sp = subprocess.call('gcc -L$ORIGIN socket.o -o socket.exe  -lwsock32 ')


