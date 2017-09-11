cache = [0 for _ in range(31)]
for i in range(28):
    cache[int(input())] = 1
for i in range(1, 31):
    if not cache[i] :
        print(i)