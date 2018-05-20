import socket
from threading import Thread
from time import sleep


# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


sock.bind(("0.0.0.0", 1234))
sock.listen(5)

def client_handling(client):
    print("Obradjujem...")
    


while(True):
    
    #ceka dok se neko ne prikaci na port (ovde je to 1234), AKA na socket koji je na portu
    client, addr = sock.accept()
    Thread(target = client_handling, args=(client, ) ).start()
    


