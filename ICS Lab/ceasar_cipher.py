def encoder():
    plaintext_old = str(input("Enter string to be encoded:"))
    plaintext=plaintext_old.upper()
    key = int(input("Enter key value:"))
    Letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    for element in list(plaintext):
        ciphertext=''
        for ch in plaintext:
            if ch in Letters:
                num = Letters.find(ch)
                num = num - key
                if num <0:
                    num = num +len(Letters)
                ciphertext=ciphertext+Letters[num]
            else:
                ciphertext=ciphertext+ch
    if plaintext_old.islower()==True:
        ciphertext=ciphertext.upper()
    else:
        ciphertext=ciphertext.lower()
    print("The cipher text is:"+ciphertext)

def decoder():
    Letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    ciphertext = str(input("Enter string to be decoded:"))
    key = int(input("Enter key value:"))
    ciphertext=ciphertext.upper()
    for element in list(ciphertext):
        plaintext = ''
        for ch in ciphertext:
            if ch in Letters:
                num = Letters.find(ch)
                num = num + key
                if num < 0:
                    num = num + len(Letters)
                plaintext = plaintext + Letters[num]
            else:
                plaintext = plaintext + ch
    print(plaintext)

encoder()
decoder()


            