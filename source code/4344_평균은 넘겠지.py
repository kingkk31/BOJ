t = int(input())
for tc in range(t) :
    arr = list(map(int, input().split()))
    sum = 0
    cnt = 0
    for i in range(1, len(arr)) :
        sum += arr[i]
    for i in range(1, len(arr)) :
        if arr[i]*arr[0] > sum :
            cnt += 1
    print("%.3f%%" % (float((cnt/arr[0])*100)))