a, b = map(int, input().split())
c, d = map(int, input().split())
e, f = map(int, input().split())
g = 0
h = 0

if a == c and c != e :
    g = e;
elif a == e and a != c :
    g = c;
elif c == e and a != e :
    g = a;
 
if b == d and d != f :
    h = f;
elif b == f and b != d :
    h = d;
elif d == f and d != b :
    h = b;
 
print("%d %d" % (g, h))
