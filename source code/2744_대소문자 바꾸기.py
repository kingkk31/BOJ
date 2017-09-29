inputStr = input()
for i in inputStr :
    if 'A' <= i and i <= 'Z' :
        print(chr(ord(i) + 32),end='')
    else :
        print(chr(ord(i) - 32),end='')