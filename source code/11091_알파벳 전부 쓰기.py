n = int(input())
for i in range(n):
    str = input()
    str = str.lower()
    alphabet = [0 for _ in range(26)]
    cnt = 26
    
    for j in range(len(str)):
        if ord(str[j]) >= ord('a') and ord(str[j]) <= ord('z') :
            if not alphabet[ord(str[j]) - ord('a')] :
                cnt -= 1
                alphabet[ord(str[j]) - ord('a')] = 1

    if cnt == 0 :
        print("pangram")
    else :
        print("missing ", end='')
        for j in range(26) :
            if not alphabet[j] :
                print(chr(ord('a') + j), end='')
        print()