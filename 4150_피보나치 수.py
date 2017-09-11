n = int(input())
a = 1
b = 1
c = 0

if n == 1 or n == 2 :
    print(1)
else :
    for i in range(3, n + 1) :
        c = a + b
        a = b
        b = c
    print(b)