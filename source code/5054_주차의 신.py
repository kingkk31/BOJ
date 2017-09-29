for i in range(int(input())):
    n = int(input())
    arr = input().split(' ')
    if n == 1:
        print('0')
    else:
        for j in range(len(arr)):
            arr[j] = int(arr[j])
        arr = sorted(arr)
        mid = int((int(arr[0]) + int(arr[n-1]))/2)
        left = (mid-int(arr[0]))*2;
        right = (int(arr[n-1])-mid)*2;
        print(left+right)