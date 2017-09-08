num = int(input())
if num%400 == 0 or (num%4 == 0 and num%100 != 0) :
    print(1)
else :
    print(0)