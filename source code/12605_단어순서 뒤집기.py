n = int(input())
for i in range(n) :
    words = input().split()
    print("Case #%d: " % (i+1), end="")
    for j in range(len(words) -1, -1, -1) :
        print(words[j], end=" ")
    print()