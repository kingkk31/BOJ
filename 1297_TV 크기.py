import math
a, b, c = map(int, input().split())
print(int(math.floor(b * math.sqrt((a*a)/(b*b+c*c)))), int(math.floor(c * math.sqrt((a*a)/(b*b+c*c)))))