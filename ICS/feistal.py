import binascii
import random

def keygen(x):
    key = ''
    for i in range(x):
        rand = random.randint(0,1)
        key += str(rand)

    return key

def exor(a,b,n):
     
    temp = ""
     
    for i in range(n):
         
        if (a[i] == b[i]):
            temp += "0"
             
        else:
            temp += "1"
             
    return temp

def feistelCipher(plainText, key):
    ptASCII = [ord(char) for char in plainText]
    ptBinary = [format(x, '08b') for x in ptASCII]
    ptBinary = ''.join(ptBinary)
    print(ptBinary)

    n = int(len(ptBinary)/2)
    leftHalf = ptBinary[0:n]
    rightHalf = ptBinary[n::]

    l1 = rightHalf

    #perform a function with key and right half (xor, for now)
    f = exor(rightHalf, key, n)
    r1 = exor(leftHalf, f, n)

    #cipher text
    ciphText = l1 + r1
    print(ciphText)
    strCiphText = ''
    for i in range (0, len(ciphText), 7):
        temp = ciphText[i:i+7]
        decCiphText = int(temp, 2)
        strCiphText += chr(decCiphText)

    return strCiphText,ciphText

def reverse(ptBinary, key):
    print(ptBinary)
    n = int(len(ptBinary)/2)
    leftHalf = ptBinary[0:n]
    rightHalf = ptBinary[n::]

    l1 = rightHalf

    #perform a function with key and right half (xor, for now)
    f = exor(rightHalf, key, n)
    r1 = exor(leftHalf, f, n)

    #cipher text
    ciphText = l1 + r1
    print(ciphText)
   
    ciphText = int(ciphText, 2)
    reverseText = binascii.unhexlify('%x'% ciphText)
    return reverseText

def main():
    plainText = input("Enter plain text: ")

    n = 8*(len(plainText)/2)
    key = keygen(int(n))

    string, ciphText = feistelCipher(plainText, key)
    print('Cipher Text: ' + string)

    reverseText = reverse(ciphText, key)
    print('Reverse Engineered Plain Text: ', reverseText)

if __name__ == "__main__":
    main()
