import socket
import hashlib

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
host = socket.gethostname()
port = 3000
s.connect((host, port))

# Send data to the server
data = b'Hello, world!'
s.send(data)

# Receive the hash from the server
hash_hex = s.recv(1024)

# Compare the hash with the locally computed hash
hash_object = hashlib.sha256(data)
hex_dig = hash_object.hexdigest()
if hash_hex.decode() == hex_dig:
    print('Hashes match!')
else:
    print('Hashes do not match.')

# Close the connection
s.close()
