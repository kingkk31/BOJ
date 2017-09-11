t = int(input())
for i in range(t) :
    arr = input().split()
    num = float(arr[0])
    for j in range(1, len(arr)) :
        if arr[j] == '@' :
            num *= 3
        elif arr[j] == '%' :
            num += 5
        else :
            num -= 7
    print("%0.2f" % (num))