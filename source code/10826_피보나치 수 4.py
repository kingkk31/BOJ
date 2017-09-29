n = 0
a = 0
b = 1
c = 0
n = int(input())

if n == 0 :
    print(a)
elif n == 1 :
	print(b)
else :
	for i in range(2, n+1) :
		c = a + b
		a = b
		b = c
	print(c)