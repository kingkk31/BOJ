people = {}
n = int(input())
for i in range(n) :
    name, status = input().split()
    if status == "enter" :
        people[name] = 1
    else :
        people[name] = 0

for j in sorted(people.keys(), reverse=True):
    if people[j] == 1 :
        print(j)