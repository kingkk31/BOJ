n = int(input())
score = sorted(map(int, input().split()))
average = 0.00
for i in score :
    average += i / score[n-1] * 100
print("%.2f" % (average/n))