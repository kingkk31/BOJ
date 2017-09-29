import math
i = 1
while True :
    str = input()
    if str == "0" :
        break;
    arr = list(map(int, str.split()))
    if (arr[0]*2)*(arr[0]*2) < (arr[1]*arr[1] + arr[2]*arr[2]) :
        print("Pizza %d does not fit on the table." % (i))
    else :
        print("Pizza %d fits on the table." % (i))
    i += 1