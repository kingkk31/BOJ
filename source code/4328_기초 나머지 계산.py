def decToRadix(n, x) :
    s = ''
    while n > 0 :
        n, r = divmod(n, x)
        s = str(r) + s
    return s
 
while True :
    line = input();
    if line == "0" :
        break
    b, p, m = map(str,line.split())
    b = int(b)
    p = int(p, b)
    m = int(m, b)
    a = p % m;
    if a == 0 :
        print(a)
    else :
        print(decToRadix(a, b))