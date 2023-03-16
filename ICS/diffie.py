import sympy
import random
n: int = 0
g: int = 0
repeat: bool = True
while repeat:
    n = int(input("Enter prime number n: "))
    if sympy.isprime(n) and n >= 3:
        repeat = False
        while True:
            g = int(input("Enter g: "))
            if sympy.is_primitive_root(n, g) and sympy.isprime(g):
                break
    else:
        print("Oops not a prime enter again !!!!")
print("Primitive root of n i.e g: ", g)
xA = random.randint(1, n - 1)
xB = random.randint(1, n - 1)
print("Private key of User A: ", xA)
print("Private key of User B: ", xB)


yA = (g ^ xA) % n
yB = (g ^ xB) % n
print("Public key of User A: ", yA)
print("Public key of User B: ", yB)

print("Public Key Exchanged")

kA = (yB ^ xA) % n
print("Symmetric key calculated by User A: ", kA)

kB = (yA ^ xB) % n
print("Symmetric key calculated by User B: ", kB)

