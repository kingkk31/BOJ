cache = [-1 for _ in range(2001)]
def tiling(w):
    if w <= 1:
        return 1
 
    if cache[w] != -1:
        return cache[w]
 
    cache[w] = (tiling(w-2)*2 + tiling(w-1))
    return cache[w]
 
n = int(input())
print(tiling(n) % 10007)