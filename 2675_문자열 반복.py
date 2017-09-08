t = int(input())
for i in range(t) :
    mul, strInput = input().split()
    multiple = int(mul)
    strOutput = ""
    for j in range(len(strInput)) :
        strOutput += strInput[j] * multiple
    print(strOutput)