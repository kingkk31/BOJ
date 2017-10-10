def init() :
    arr = []
    for i in range(1, 10) :
        for j in range(1, 10) :
            if i == j :
                continue
            for k in range(1, 10) :
                if i == k or j == k :
                    continue
                arr.append(str(i*100 + j*10 + k))
    return arr
 
def solve(ball, num, s, b) :
    checkS, checkB = 0, 0
    for i in range(3) :
        for j in range(3) :
            if ball[i] == num[j] :
                if i == j :
                    checkS += 1
                else :
                    checkB += 1

    if checkS == s and checkB == b :
        return True
    else :
        return False
    

numbers = init()
n = int(input())

for t in range(n) :
    data = list(map(int, input().split()))
    data[0] = str(data[0])

    for i in range(len(numbers)) :
        if numbers[i] == "000" :
            continue
        if solve(data[0], numbers[i], data[1], data[2]) == False :
            numbers[i] = "000"

cnt = 0
for i in numbers :
    if i != "000" :
        cnt +=1
print(cnt)