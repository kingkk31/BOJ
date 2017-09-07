n = int(input())
arr = []
for i in range(n) :
    arr.append(int(input()))
arr.sort()
maxi = 0
for i in range(n) :
    maxi = max(maxi, arr[i] * (n-i))
print(maxi)