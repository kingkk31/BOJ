import sys
for t in sys.stdin:
    t = int(t)
    st = set()
    for i in range(t) :
        str = input()
        exp = ""
        balloon = []
        for j in str :
            if j not in balloon :
                balloon.append(j)
        balloon.sort()
        exp = "".join(balloon)
        st.add(exp)
    print(len(st))