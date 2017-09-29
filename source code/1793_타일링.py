cache = [-1 for _ in range(501)]
def tiling(w):
    if w <= 1:
        return 1

    if cache[w] != -1:
        return cache[w]

    cache[w] = (tiling(w-2)*2 + tiling(w-1))
    return cache[w]

import sys
for line in sys.stdin:
    n = int(line)
    print(tiling(n))