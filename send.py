import socket

soc = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while(True):
    data = input()# nesto
    soc.sendto(data.encode("ascii"), ("192.168.0.101", 1234) )