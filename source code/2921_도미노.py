a = int(input())
total = 0
for i in range(a+1):
	temp = i*(a+1-i)
	for j in range(i, a+1):
		temp += j
	total += temp
print(total)