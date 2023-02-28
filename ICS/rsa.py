import math
from primePy import primes

def is_prime(n):
  for i in range(2,n):
    if (n%i) == 0:
      return False
  return True

p, q = map(int, input("Enter p and q :").split()) 

if primes.check(p) and primes.check(q) == True:
    n = p*q
    phi_n = (p-1)*(q-1)
    e_pos=[]
    for i in range(2,phi_n):
        if math.gcd(i,phi_n) == 1:
            e = i
            e_pos.append(e)
    print(e_pos)
    print(len(e_pos))
    r =int(input("Select e value"))
    for j in range(phi_n-1):
        if (r*j) % phi_n == 1:
           d = j;
           print(d)
           break;
    a=int(input("Enter number to encrypt:"))
    enc = pow(a,r) % n
    dec = pow(enc,d) % n 
    print("Ciphertext is",enc)
    print("Decrypted text is",dec)



     
  

   
      

  

