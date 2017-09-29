def getPrime(number) :
    primeList = [2]
    num = 3
    while (num <= number): 
        for i in primeList:
            if(num % i == 0):
                break
            elif(i == primeList[-1]):
                primeList.append(num)
                break
        num += 1
    return primeList

def solve(arr, n) : 
    for i in arr :
        for j in arr :
            if(i < j) :
                continue
            for k in arr :
                if(j < k) :
                    continue
                if i + j + k == n :
                    print("%d %d %d" % (k, j, i))
                    return
    print(0)

primeArr = getPrime(1000)
for i in range(int(input())) :
    solve(primeArr, int(input()))