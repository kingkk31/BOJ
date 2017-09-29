n = int(input())
score = [0 for i in range(n)]
arr = [[0 for col in range(3)] for row in range(n)]

for i in range(n) :
    arr[i][0], arr[i][1], arr[i][2] = map(int, input().split())

for k in range(3) :
    for i in range(n) :
        flag = False
        for j in range(n) :
            if i == j :
                continue
            if arr[i][k] == arr[j][k] :
                flag = True
        if flag == False :
            score[i] += arr[i][k]

for i in score :
    print(i)