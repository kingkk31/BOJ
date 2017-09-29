val = input()
cnt = 0
while len(val) != 1 :
    sum = 0
    for i in val :
        sum += int(i)
    val = str(sum)
    cnt += 1
num = int(val)
print(cnt)
if num == 3 or num == 6 or num == 9 :
    print("YES")
else :
    print("NO")