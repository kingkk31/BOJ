from math import sqrt
num = int(input())
n = int(sqrt(num*2))
while num * 2 < n * (n + 1) :
    n -= 1
print(int(n))