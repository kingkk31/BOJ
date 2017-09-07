import sys
n = int(sys.stdin.readline())
cnt = 1
for i in range(n) :
    cnt += int(sys.stdin.readline()) - 1
print(cnt)