ans = 0
sum = 0
for i in range(10) :
    score = int(input())
    sum += score
    if abs(100 - sum) < abs(100 - ans)  or (abs(100 - sum) == abs(100 - ans) and sum > ans):
        ans = sum
print(ans)