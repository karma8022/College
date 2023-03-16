import hashlib
from PIL import Image
str = input("Enter string: ")
result = hashlib.md5(str.encode())
print(result)
str1 = input("Enter string to be crosschecked: ")
result1 = hashlib.md5(str1.encode())
print(result1)
if result1==result :
    print("Data has not been tampered with")
else :
    print("Data has been tampered with")
