import random 
import binascii



IP = [2,6,3,1,4,8,5,7]
IP_inverse = [4,1,3,5,7,2,8,6]
P10 = [2,4,1,6,3,9,0,8,7,5]
P8 = [5,2,6,3,7,4,19,8]
P4 = [1,3,2,0]
E_P=[3,0,1,2,1,2,3,0]
S0=[[1,0,3,2],
    [3,2,1,0],
    [0,2,1,3],
    [3,1,3,2]]
    
S1=[[0,1,2,3],
    [2,0,1,3],
    [3,0,1,0],
    [2,1,0,3]]

def key_gen():
    Key=[]
    print("Enter key")
    for i in range(10):
        Key.append(int(input()))
    for i in range(10):
        Key[i]=Key[P10[i]]
    l_split=(Key[:5])
    print(l_split)
    r_split=(Key[5:])
    l_split = join(l_split)
    print(l_split)
key_gen()


