from collections import Counter
arr = []
sum = 0
for i in range(10) :
    arr.append(int(input()))
    sum += arr[i]
print(int(sum/10))
cnt = Counter(arr)
print(cnt.most_common(1)[0][0])