import subprocess
import string
import ctypes
import time
import sys
import os
import signal

from ctypes import (CFUNCTYPE, POINTER,
                    cast, cdll, util,
                    c_bool, c_char, c_char_p, c_int, c_uint, c_void_p)

sp = subprocess.Popen(
        "./deamon.exe",            
        stdin = subprocess.PIPE, 
        stdout = subprocess.PIPE, close_fds=True
)
response = sp.stdout.readline()

index = str(response.decode()).split(",") 
print(index)
C = c_uint(int(index[0]))

PING = cdll.LoadLibrary("./channel.dll")
PING.token(C)

try:
    a = c_char_p(''.encode('utf-8'))
    PING.get(a)
    print (a.value)
    b = c_char_p('!453'.encode('utf-8'))
    PING.set(b)
    c = c_char_p(''.encode('utf-8'))
    PING.get(c)
    print (c.value)
    print (index[1])
    #os.kill(int(index[1]), signal.SIGINT)
    retcode = subprocess.check_output("kill -INT " + index[1] + "", shell=True)
    print (retcode)
    os.kill(int(index[1]), signal.SIGQUIT)
except:
    print (sys.exc_info()[0])
    exit(0)