for i in range(int(input())):
    arr = input().split(' ')
    index = int(arr[0])
    for j in range(len(arr[1])):
        if index - 1 == j:
           continue
        print(arr[1][j], end='')
    print()