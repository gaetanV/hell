import subprocess
import time
from ctypes import (CFUNCTYPE, POINTER,
                    cast, cdll, util,
                    c_bool, c_char, c_char_p, c_int, c_uint, c_void_p)

sp = subprocess.call("./broker/broker.exe A -store=mem,400 -broker=B1,B2 -delivery=inner -brokermode=unique   -archive=true")
#sp = subprocess.call("./broker.exe B -store=mongo   -broker=B1,B2 -delivery=inner -brokermode=replicat -archive=true")
#sp = subprocess.call("./broker.exe C -store=file     -broker=B1   -delivery=outer -brokermode=unique   -archive=true")

time.sleep(1)
PING = cdll.LoadLibrary("./interface/channelwindow.dll")
a = c_char_p(''.encode('utf-8'))
PING.get(a)
print (a.value)

sp = subprocess.call("Taskkill /IM broker* /F")
