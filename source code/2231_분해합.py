n = int(input())
flag = False
for i in range(n) :
    temp = sum = i
    while temp != 0 :
        sum += temp % 10
        temp //= 10
    if n == sum :
        print(i)
        flag = True
        break
if flag == False :
    print(0)