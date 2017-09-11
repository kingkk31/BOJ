a, b = map(int, input().split())
num, cnt, sum, temp = 1, 0, 0, 0
for i in range(1, b+1) :
    sum += num
    if i == a - 1 :
        temp = sum
    cnt += 1
    if num == cnt :
        cnt = 0
        num += 1
print(sum - temp)