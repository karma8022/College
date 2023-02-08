print("Hello World")

a=5
print(a)

a = input("Enter name")
b = input("Enter gender")
c = int(input("Enter age"))
print(a,b)
print(c)

a = int(input("Enter first number"))
b = int(input("Enter second number"))
print(a+b)

name,age = input("Enter name,Enter age").split()
print(name)
print(age)

a = int(input("Enter a"))
b = int(input("Enter b"))
c = int(input("Enter c"))
if a > b and a > c:
    print(a)
elif b > a and b > c:
    print(b)
else:
    print(c)