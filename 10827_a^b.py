a, b = map(float,input().split())
a = str(a)
dot = len(a) - a.find('.') - 1
a = a.replace('.', '')
b = int(b)
num = str(pow(int(a), b))
num = num.zfill(dot * b)
front = num[:len(num) - dot*b].zfill(1) #소수점 앞
print(front, end='')
if len(num[len(num) - dot*b:].rstrip('0')) > 0:
    print('.' + num[len(num) - dot*b:].rstrip('0'), end='')
print()