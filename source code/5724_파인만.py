while True :
    n = int(input())
    if n == 0 :
        break
    cnt = 0
    for i in range(1, n+1) :
        cnt += pow(i, 2)
    print(cnt)