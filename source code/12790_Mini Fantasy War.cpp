n = int(input())
for i in range(n) :
    hp, mp, offense, armor, hp2, mp2, offense2, armor2 = map(int, input().split())
    hp += hp2
    mp += mp2
    offense += offense2
    armor += armor2
    
    if hp < 1 :
        hp = 1
    if mp < 1 :
        mp = 1
    if offense < 0 :
        offense = 0
    print(1 * hp + 5 * mp + 2 * offense + 2 * armor)