n = int(input())
arr = []
for i in range(1, n+1) :
    arr.append(i)

while len(arr) > 1 :
    print(arr.pop(0), end=' ');
    for i in range(len(arr) - 1) :
        temp = arr[i]
        arr[i] = arr[i+1]
        arr[i+1] = temp;
print(arr[0])