import sys
for line in sys.stdin:
    for i in range(0, len(line)-1, 2) :
        code = line[i] + line[i+1]
        print(chr(int(code, 16)), end='')
    print()