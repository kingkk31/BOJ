import math
  
n,k = input().split()
  
n = int(n)
k = int(k)
  
sum = math.factorial(n)//math.factorial(n-k)//math.factorial(k)
  
print("%d" % sum)