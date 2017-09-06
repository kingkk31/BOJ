num = int(input())
arr = [64]
sum = 64

while True :
    if sum == num : 
        break;
    arr.sort()
    min = arr.pop(0)
    if sum - (min/2) >= num :
        sum = sum - (min/2)
        arr.append(min/2)
    else :
        arr.append(min/2)
        arr.append(min/2)
    
print(len(arr))    