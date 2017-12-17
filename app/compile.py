import subprocess

sp = subprocess.call("gcc -m32 -c ./interface/channelwindow.c  ")
sp = subprocess.call("gcc -m32 -shared -o ./interface/channelwindow32.dll ./channelwindow.o")

sp = subprocess.call("gcc -m64 -c ./interface/channelwindow.c  ")
sp = subprocess.call("gcc -m64 -shared -o ./interface/channelwindow64.dll ./channelwindow.o")

sp = subprocess.call("gcc ./broker/broker.c -o ./broker/broker.exe")
sp = subprocess.call("gcc ./broker/brokerwindow.c -o ./broker/brokerwindow.exe")