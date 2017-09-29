arr = [0 for _ in range(0, 10)]
mini = 99876543210
maxi = 0
miniStr = "99876543210"
maxiStr = "0"

def solve(s) :
    global mini
    global maxi
    global miniStr
    global maxiStr    
    
    if len(s) == n+1 :
        if maxi < int(s) :
            maxi = int(s)
            maxiStr = s
        if mini > int(s) :
            mini = int(s)
            miniStr = s
        return

    back = s[len(s)-1]
    if inequality[len(s)-1] == '<' :
        for i in range(int(back)+1, 10) :
            if arr[i] == 1 :
                continue
            arr[i] = 1
            s += str(i)
            solve(s)
            s = s[:len(s)-1]
            arr[i] = 0
    else :
         for i in range(int(back)-1, -1, -1) :
            if arr[i] == 1 :
                continue
            arr[i] = 1
            s += str(i)
            solve(s)
            s = s[:len(s)-1]
            arr[i] = 0
          
    return

n = int(input())
inequality = input().split()

for i in range(0, 10) :
    arr[i] = 1
    strNum = str(i)
    solve(strNum)
    arr[i] = 0

print(maxiStr)
print(miniStr)

