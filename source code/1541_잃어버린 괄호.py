arr1 = input().split('-')
arr2 = []
for i in arr1 :
    temp = i.split('+')
    num = 0
    for j in temp :
        num += int(j)
    arr2.append(num)    
sum = int(arr2[0])
for i in range(1, len(arr2)) :
    sum -= int(arr2[i])
print(sum)