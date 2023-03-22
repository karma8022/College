from crypt import pkcs1_15
from crypto.Hash import SHA256
from crypto.PublicKey import RSA

# Generate a new RSA key pair
key = RSA.generate(2048)

# The message to be signed
message = b"Hello, world!"

# Compute the SHA-256 hash of the message
h = SHA256.new(message)

# Create a signer object using the private key
signer = pkcs1_15.new(key)

# Sign the hash of the message
signature = signer.sign(h)

# Verify the signature using the public key
verifier = pkcs1_15.new(key.publickey())
try:
    verifier.verify(h, signature)
    print("The signature is valid.")
except:
    print("The signature is invalid.")
