from collections import deque

parrots = []
n = int(input())
for i in range(n) :
    memory = input().split()
    qu = deque()
    for word in memory :
        qu.append(word)
    parrots.append(qu)

written = input().split()
ans = 1 
for word in written :
    flag = False
    for parrot in parrots :
        if len(parrot) != 0 and parrot[0] == word :
            parrot.popleft()
            flag = True
            break
    if flag == False :
        ans = 0
        break

for parrot in parrots :
    if len(parrot) != 0 :
        ans = 0
        break

if ans == 1 :
    print("Possible")
else : 
    print("Impossible")