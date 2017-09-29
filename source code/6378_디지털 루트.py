while True:
    n = input()
    if n == "0" :
        break

    while True :
        sum = 0
        for i in n :
            sum += int(i)
        if sum < 10 :
            print(sum)
            break;
        n = str(sum)