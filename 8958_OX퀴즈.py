t = int(input())
for l in range(t) : 
    score = 0
    n = 0
    check = input()
    
    for i in check :
        if i == 'X' :
            n = 0
        else :
            n += 1
        score += n
    print(score)
