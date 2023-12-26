F = 0
#//////////////////////////////////////////////////
#//              part 2 pending                  //
#//////////////////////////////////////////////////
r1, r2 = 0, 0
A = []
import math
with open('21.' + str(F)) as file:
    for line in file:A.append(line.strip())
def dbg( Thing, name=None ):
    if name: print(name)
    if isinstance(Thing, dict):
        Dict = Thing
        print(Dict)
        for k,v in Dict.items(): print(k,v)
    if isinstance(Thing, list):
        things = Thing
        print(things)
        for thing in things: print( thing )
    print()
start = (None, None)
R, C = len(A),len(A[0])
for r in range(R):
    for c in range(C):
        if A[r][c] == 'S': start = (r, c, 0)

dbg(A)

D = [ start ]
P,seen, = set(), {(r,c)}
DR=[1,0,-1,0]
DC=[0,1,0,-1]
while D:
    #dbg(D)
    r,c,dist = D.pop(0)
    if r < 0 or r > R - 1 or c < 0 or c > C - 1 or (r,c) in seen or A[r][c] == '#':
        continue
    seen.add((r,c))
    if dist <= 64 and dist % 2 == 0:
        P.add((r,c))
    for i in range(4):
        pos = (r + DR[i], c + DC[i], dist + 1)
        D.append(pos)

r1 = len(P)

print("part 1:", r1)
print("part 2:", r2)

