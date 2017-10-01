T = int(input())
for t in range(T) :
    sum = 0
    card = (" ".join(input())).split()
    card.reverse()
    for i in range(len(card)) :
        card[i] = int(card[i])
        if i % 2 != 0 :
            card[i] *= 2
        if card[i] > 9 :
            card[i] = (card[i] // 10) + (card[i] % 10)
        sum += card[i]
    if sum % 10 == 0 :
        print("T")
    else : 
        print("F")