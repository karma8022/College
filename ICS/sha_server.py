import socket
import hashlib

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a public host and port
host = socket.gethostname()
port = 3000
s.bind((host, port))

# Listen for incoming connections
s.listen(5)

while True:
    # Wait for a client to connect
    c, addr = s.accept()
    print('Got connection from', addr)
    
    # Receive data from the client
    data = c.recv(1024)
    
    # Hash the data using SHA-256
    hash_object = hashlib.sha256(data)
    hex_dig = hash_object.hexdigest()
    
    # Send the hash back to the client
    c.send(hex_dig.encode())
    
    # Close the connection
    c.close()
