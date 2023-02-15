import random 
import binascii

def keygen(x):
    key=''
    for i in range(x):
        key += str(random.randint(0,1))
    return key


def exor(a,b,n):
     
    temp = ""
     
    for i in range(n):
         
        if (a[i] == b[i]):
            temp += "0"
             
        else:
            temp += "1"
             
    return temp

def feistal(plaintext,key):
    ptASCII=[ord(char) for char in plaintext]
    ptBinary=[format(x,'8b') for x in ptASCII]
    ptBinary=''.join(ptBinary)
    print(ptBinary)
