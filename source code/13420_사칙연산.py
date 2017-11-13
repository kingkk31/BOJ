def calculate(val, num, operator) :
    if operator == "+" :
            val += num
    elif operator == "-" :
            val -= num
    elif operator == "*" :
            val *= num
    elif operator == "/" :
            val //= num
    return val
        
n = int(input())
for t in range(n) :
    formula = input().split()
    val, ans = int(formula[0]), int(formula[len(formula)-1])
    
    i = 1
    while formula[i] != "=" :
        if formula[i] != "+" and formula[i] != "-" and formula[i] != "*" and formula[i] != "/" :
            val = calculate(val, int(formula[i]), formula[i-1])
        i += 1

    if val == ans :
        print("correct")
    else :
        print("wrong answer")