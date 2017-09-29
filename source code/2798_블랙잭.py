n, m = map(int, input().split())
card = list(map(int, input().split()))
ans = 0
for i in range(0, n) :
    for j in range(0, n) :
        if i == j :
            continue
        for k in range(0, n) :
            if i == k or j == k :
                continue
            if card[i] + card[j] + card[k] <= m :
                ans = max(ans, card[i] + card[j] + card[k])
print(ans)