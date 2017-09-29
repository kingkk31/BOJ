while True :
    n = int(input())
    if n == 0 :
        break

    while True : 
        print(n, end=' ')
        if n < 10 :
            break;

        arr = str(n)
        n = 1
        for i in arr :
            n *= int(i)
    
    print()