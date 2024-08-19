# Probabilistic Algorithm for Factoring n = pq, where p and q are prime numbers
# Single Trial of the Algorithm

# import math
# import random
# n = int(input("Enter n: "))
# order=[]
# m = 1
# Znstar = [i for i in range(1,n) if math.gcd(i,n)==1] # Zn* = {1,2,3,...,n-1} where gcd(i,n) = 1
# for i in Znstar:
#     while (i ** m) % n != 1:
#         m+=1
#     order.append(m)
#     m=1

# print("Order of all elements in Zn*: ",order)
# exponent = max(order) 
# print("Exponent of Zn*: ",exponent)
# while exponent % 2 == 0:
#     exponent = exponent//2
# t = exponent
# alpha = random.randint(1,n)
# print("Alpha: ",alpha)
# g = math.gcd(alpha,n)
# if g != 1:
#     print("Factors are: ",g,n//g)
# else:
#     B = alpha**t
#     repB = B % n
#     ans=(math.gcd(repB +1,n))
#     if (ans != 1) and (ans != n):
#         print("Factors are: ",ans,n//ans)
#     else:
#         print("Failure")



# Probabilistic Algorithm for Factoring n = pq, where p and q are prime numbers
# Multiple Trials of the Algorithm

import math
import random
n = int(input("Enter n: ")) # n = pq
trials = int(input("Enter number of trials: "))
order=[]
m = 1
Znstar = [i for i in range(1,n) if math.gcd(i,n)==1] # Zn* = {1,2,3,...,n-1} where gcd(i,n) = 1
for i in Znstar:
    while (i ** m) % n != 1:
        m+=1
    order.append(m)
    m=1

print("Order of all elements in Zn*: ",order)
exponent = max(order) 
print("Exponent of Zn*: ",exponent)
while exponent % 2 == 0:
    exponent = exponent//2
t = exponent

flag=0
factors = []
for i in range(trials):
    alpha = random.randint(1,n)
    print("Alpha: ",alpha)
    g = math.gcd(alpha,n)
    if g != 1:
        # print("Factors are: ",g,n//g)
        flag=1
        if g>n//g:
            factors = [n//g,g]
        else:
            factors = [g,n//g]
    else:
        B = alpha**t
        repB = B % n
        ans=(math.gcd(repB +1,n))
        if (ans != 1) and (ans != n):
            # print("Factors are: ",ans,n//ans)
            flag=1
            if ans>n//ans:
                factors = [n//ans,ans]
            else:
                factors = [ans,n//ans]

if flag==1:
    print("Success")
    print("Factors are: ",*factors)
else:
    print("Failure")



# Success Probability of the Algorithm : 1 - (1/2)^trials
