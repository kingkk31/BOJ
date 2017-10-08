def gcd(a, b) :
    if b == 0 :
        return a
    return gcd(b, a%b)

T = int(input())
for t in range(T) :
    sum = 0
    arr = list(map(int, input().split()))
    for i in range(1, len(arr) - 1) :
        for j in range(i + 1, len(arr)) :
            sum += gcd(arr[i], arr[j])
    print(sum) 