n, b = map(int, input().split())
ans = ""
while n != 0 :
    num = n % b
    if num >= 10 :
        ans = "" + chr(55 + num) + ans
    else :
        ans = "" + chr(ord('0') + num) + ans
    n //= b
print(ans)
