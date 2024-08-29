# Probabilistic Algorithm for Factoring n = pq, where p and q are prime numbers
# Verifying the probability of success is atleast 1/2

import math
n = int(input("Enter n: "))
order=[]
m = 1
Znstar = [i for i in range(1,n) if math.gcd(i,n)==1] # Zn* = {1,2,3,...,n-1} where gcd(i,n) = 1
for i in Znstar:
    while pow(i,m,n) != 1:
        m+=1
    order.append(m)
    m=1

print("Order of all elements in Zn*",order)
exponent = max(order) #f
owais = exponent
print("Exponent of Zn*",exponent)
# f = exponent ( it can be any positive integer multiple of exponent)
while exponent % 2 == 0:
    exponent = exponent//2

t = exponent
Znplus = [i for i in range(1,n)] # Zn = {1,2,3,...,n-1}
sucess_alpha = []
failure_alpha = []
for i in Znplus: #Computing Probability of Success for all elements in Zn to verify the probability of success of the algorithm
    g = math.gcd(i,n)
    if g != 1:
        sucess_alpha.append(i)
        print("Factors are1: ",g,n//g)
    else:
        B = i**t
        repB = B % n
        ans=(math.gcd(repB +1,n))
        if (ans != 1) and (ans != n):
            print("Factors are2: ",ans,n//ans)
            sucess_alpha.append(i)
        else:
            print("Failure")
            failure_alpha.append(i)

print("Alpha Success: ",*sucess_alpha)
print("Count of Alpha Success: ",len(sucess_alpha))
print("Alpha Failure: ",*failure_alpha)
print("Count of Alpha Failure: ",len(failure_alpha))
print("Success Probability: ",len(sucess_alpha)/len(Znplus))
print("Exponent of Zn*",owais)