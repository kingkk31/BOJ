def hanoi(n, a, b, c, N) :
    if n == 1 :
        print("%d %d" % (a, c))
        return
    hanoi(n - 1, a, c, b, N)
    print("%d %d" % (a, c))
    hanoi(n - 1, b, a, c, N)    

n = int(input())
print(pow(2,n) - 1)
if n <=20 :
    hanoi(n, 1, 2, 3, n)