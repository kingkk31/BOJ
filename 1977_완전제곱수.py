import math
a, b = int(input()), int(input())
arr = []
total = 0
for i in range(a,b+1):
	if int(math.sqrt(i))**2 == i:
		total += i
		arr.append(i)

if not arr:
	print(-1)
else:
	print(total)
	print(arr[0])