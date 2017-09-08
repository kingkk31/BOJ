n = int(input())
maxi = 0
for t in range(n) :
    a, b, c = map(int, input().split())
    if a == b and b == c :
        maxi = max(maxi, 10000 + a*1000)
    elif a == b :
        maxi = max(maxi, 1000 + a*100)
    elif a == c :
        maxi = max(maxi, 1000 + a*100)
    elif c == b :
        maxi = max(maxi, 1000 + c*100)
    else :
        maxi = max(maxi, max(a, b, c)*100)
print(maxi)