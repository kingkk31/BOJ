arr = input().split()
circle = input().split()
person = -1
for i in range(len(arr)) :
    if int(arr[i]) == int(circle[0]) :
        person = i;
print(person + 1)