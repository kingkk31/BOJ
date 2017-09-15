n = int(input())
for i in range(n) :
	arr = input().split()
	for j in arr :
		print(j[::-1], end=' ')
	print()