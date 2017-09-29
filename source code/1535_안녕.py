def solve(pos, hp, joy) :
    global ans
    if pos >= n :
        ans = max(ans, joy)
        return
    if hp-hpArr[pos] > 0 :
        solve(pos+1, hp-hpArr[pos], joy+joyArr[pos])
    solve(pos+1, hp, joy)
    
n = int(input())
hpArr = list(map(int, input().split()))
joyArr = list(map(int, input().split())) 
ans = 0
solve(0, 100, 0)
print(ans)