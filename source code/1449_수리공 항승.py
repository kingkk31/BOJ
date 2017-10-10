n, l = map(int, input().split())
hole = sorted(list(map(int, input().split())))
ans, pos = 1, 0
for i in range(n) :
    if hole[i] - hole[pos] >= l :
        pos = i
        ans += 1
print(ans)