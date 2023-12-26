F = 0
r1, r2 = 0, 0
A = []
from collections import defaultdict
with open('18.' + str(F)) as file:
    for line in file:
        A.append(line.strip())
def Shoelace(A, p2=False) -> int:
    DIR = ['R','D','L','U'] # part 2
    curr=(0,0)
    D=[curr]
    peri = 0
    res = None
    for a in A:
        r, c = [*curr]
        d, n, line = a.split()
        n=int(n)
        if p2:
            d = DIR[ int(line[-2]) ]
            n = int(line[2:7], 16)
        if d == 'R':
            c+=n
        elif d == 'D':
            r+=n
        elif d == 'L':
            c-=n
        elif d == 'U':
            r-=n
        curr = (r,c)
        peri += n
        D.append(curr)
    # Shoelace + Pick 👇
    up,down=0,0
    for i in range(len(D) - 1):
        curr, next = D[i], D[i+1]
        up = up + curr[0] * next[1]
        down = down + curr[1] * next[0]
    up += D[-1][0] * D[0][1]
    down += D[0][0] * D[-1][1] # get lst layer
    area = abs(up - down) // 2
    pick = area - peri // 2  + 1
    res = peri + pick

    if not p2:
        print(D)
        lenV=len(D)
        print('sizeof vertices:',lenV,'should be:',38)
        print('sizeof allcoors:',peri,'should be:',38)
        print('way 3 full area:',area)
        print('way 3 perimeter:',peri)
        print('way 3 pick fact:',pick)
        print('way 3 true area:',res)
        print()
    return res

r1 = Shoelace(A, False)
r2 = Shoelace(A, True)
print("part 1:", r1)
print("part 2:", r2)

assert(r1 in [47675,62])
assert(r2 in [122103860427465, 952408144115])
