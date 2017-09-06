ans = [0 for _ in range(10)]

def calc(n, ten) :
    while n > 0 :
        ans[n%10] += ten
        n = int(n/10)

start = 1
end = int(input())
ten = 1
    
while start <= end :
    while start % 10 != 0 and start <= end :
        calc(start,ten)
        start += 1
        
    if start > end :
        break

    while end % 10 != 9 and start <= end :
        calc(end,ten)
        end -= 1
    
    cnt = (int(end/10) - int(start/10) + 1)
    for i in range(10) :
        ans[i] += cnt*ten
    
    start = int(start / 10)
    end = int(end / 10)
    ten = ten*10
    
for i in range(10) :
    print(ans[i], end = ' ')
print()