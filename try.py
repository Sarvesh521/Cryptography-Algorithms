import math
n = int(input("Enter n: "))
order=[]
m = 1
Znstar = [i for i in range(1,n) if math.gcd(i,n)==1] # Zn* = {1,2,3,...,n-1} where gcd(i,n) = 1
for i in Znstar:
    # print("i: ",i) # To check if the code is running
    while (i ** m) % n != 1:
        m+=1
    order.append(m)
    m=1

print("Order of all elements in Zn*",order)
exponent = max(order) 
owais = exponent
print("Exponent of Zn*",exponent)
h=0
while exponent % 2 == 0:
    exponent = exponent//2
    h+=1
# t = exponent
t = 90
G = [ i for i in Znstar if ((i**t) % n in [1,n-1])]
print("G: ",G)
print("Count of G: ",len(G)) 
print("count of Znstar: ",len(Znstar))
print("Expontent of Zn*: ",owais)