a,b,c=int(input()),int(input()),int(input())
arr = str(a*b*c)
for i in range(10):
	print(arr.count(str(i)))