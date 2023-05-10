import hashlib

def calculate_sha(text):
    sha = hashlib.sha256()
    sha.update(text.encode())
    sha_digest = sha.hexdigest()
    return sha_digest

# Example usage
text1 = input("Enter the first text: ")
text2 = input("Enter the second text: ")

hash1 = calculate_sha(text1)
hash2 = calculate_sha(text2)

print("Hash 1:", hash1)
print("Hash 2:", hash2)

if hash1 == hash2:
    print("The hashes are the same.")
else:
    print("The hashes are different.")
