n = int(input())
cnt = 0
arr = map(int, input().split())
for i in arr :
    if i == n :
        cnt += 1
print(cnt)