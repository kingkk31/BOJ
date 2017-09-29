n = int(input())
for i in range(1, n+1):
    num = input().split(" ")
    a,b = int(num[0]), int(num[1])
    print("Scenario #%d: " % (i))
    print(int((a+b)*(b+(a*-1)+1)//2))
    if i != n :
        print()
    