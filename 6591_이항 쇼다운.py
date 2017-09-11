while True :
    n,k = map(int, input().split())
    if n == 0 and k == 0 :
        break
    t = n - k
    if t < k :
        t, k = k, t
    
    ans = 1    
    for i in range(1, k + 1) :
        ans *= n
        n -= 1
        ans //= i
    print("%d" % ans)