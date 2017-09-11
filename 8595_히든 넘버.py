n = int(input())
str = input()
number = "0"
sum = 0
for i in range(n) : 
    if str[i] >= '0' and str[i] <= '9' :
        number += str[i]
    else :
        sum += int(number)
        number = "0"
sum += int(number)
print(sum)