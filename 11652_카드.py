n = int(input())
numbers = {}

for i in range(n) :
    num = int(input())
    if num in numbers :
        numbers[num] += 1
    else :
        numbers[num] = 1

index = max(numbers, key = numbers.get)
maxi = numbers[index]

for key, value in numbers.items() :
    if value == maxi :
        index = min(key, index)
print(index)