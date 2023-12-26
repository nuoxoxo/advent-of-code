F = 0
import functools
from collections import Counter
### 251473971 . 252357948 too lo .. 252348193 x -- p1
### 247693206 . 252075685 too lo .. 255266595 too hi . 254469345 . 254457089 - part 2
r1, r2 = 0, 0
A,E=[],[]
with open('07.' + str(F)) as file:
    for line in file:
        line=line.strip().split()
        L,R = line[0],line[1]
        L = L.replace('A','|')\
            .replace('K','_')\
            .replace('Q','^')\
            .replace('J',']')\
            .replace('T','[') # can make a func
        line[0] = L
        counter = Counter(line[0])
        findmost = counter.most_common()
        paircount = findmost[0][1]
        if paircount not in [4,5]:# 2 pair > 1 pair > Set
            if paircount == 3: # aaabb > aaabc
                if findmost[1][1] == 2:
                    paircount = 3 # aaabb
                elif findmost[1][1] == 1:
                    paircount = 2 # aaabc
            elif paircount == 2:
                if findmost[1][1] == 2: # aabbc > aabcd
                    paircount = 1 # aabbc
                else:
                    paircount = 0 # aabcd
            elif paircount == 1:
                paircount = -1 # floor: all uniq
        S, s = set(), ''
        for c in L:
            if c not in S:
                S.add(c)
                s+=c # wrong? to rev later
        line[1] = int(R)
        line.append(paircount)
        A.append(line)
        E.append([line[0], int(R)])

def dbg(thing):
    for n in thing:print(n)

def cmp(ll, rr):
    l,r=ll[0],rr[0]
    c1,c2=ll[2],rr[2]
    if c1==c2:
        for a,b in zip([_ for _ in l], [_ for _ in r]):
            if ord(a) > ord(b):return 1
            elif ord(a) < ord(b):return -1
        return 0
    return (c1 > c2) - (c1 < c2)
    """elif c1 > c2: return 1
    elif c1 < c2: return -1
    return 0
    """
cardtypes = [']', '2', '3', '4', '5', '6', '7', '8', '9', '[', '^', '_', '|']
def cmp2(ll, rr):
    # to make: best possible hand
    l, r = ll[0], rr[0] # original pair to cmp
    Jall, L, R = ']]]]]', '', '' # ]]]]] ---> 5xJ
    if l == Jall:
        L = '|||||' # ||||| ---> 5xA
    else:
        L = ll[0].replace(']', '')
    if rr[0] == Jall:
        R = '|||||'
    else:
        R = rr[0].replace(']', '')
    pair = [L, R]
    LR = []
    for hand in pair:
        ln = len(set(hand))
        counter = Counter(hand)
        findmost = counter.most_common()
        LR.append(findmost[0][1] - ln)
    maxL, maxR = LR
    if ']' in l and l != Jall:
        maxL += l.count(']')
    if ']' in r and r != Jall:
        maxR += r.count(']')
    if maxL < maxR:return -1
    if maxL > maxR:return 1
    # same power
    for i in range(5):
        c1 = cardtypes.index(l[i])
        c2 = cardtypes.index(r[i])
        if c1 < c2:return -1
        if c1 > c2:return 1
    return 0


A.sort(key=functools.cmp_to_key(cmp))
for i in range(len(A)): r1 += A[i][1] * (i + 1)
#dbg(E)#A)

E.sort(key=functools.cmp_to_key(cmp2))
for i in range(len(E)): r2 += E[i][1] * (i + 1)
dbg(E)#A)

print('part 1:', r1)
print('part 2:', r2)

exit()

# ----------------------------#
# part 2 - deprecated
cardtypes=[] # fill with all card types
BB,B=A.copy(),[] # for part 2
"""deprecated
for line in B:
    print(line)
    b = []
    s,pts,=line
    if ']' not in s:
        b.append(line)
        B.append(b)
        continue
    for ct in cardtypes:
        ss=s.replace(']', ct)
        b.append([ss, pts])
    # ^ i think thats it
    # todo: use cmp logic to a sorted subgroup
    # keep the best ie. top of the sorted subg
for b in B:
    b[0].sort(key=functools.cmp_to_key(cmp))
    b[0]=b[0][0]

A.sort(key=functools.cmp_to_key(cmp))
B.sort(key=functools.cmp_to_key(cmp))
for a in A:print(a)
for i in range(len(A)):
    r1 += A[i][1] * (i+1)
for i in range(len(B)):
    r2 += B[i][1] * (i+1)
print(r1,r2)
"""

