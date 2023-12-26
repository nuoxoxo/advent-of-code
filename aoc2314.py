F = 0
r1, r2 = 0, 0
A = []
def dbg(T):
    for t in T:print(' '.join(t))
    print()
with open('14.' + str(F)) as file:
    for line in file:
        A.append([_ for _ in line.strip()])
p1, p2 = [list(_) for _ in A], [list(_) for _ in A]

def RollingLeft(A):
    nomove = [[] for _ in range(len(A))]
    for i,a in enumerate(A):
        if '#' not in a:
            continue
        for index, char in enumerate(a):
            if char == '#':
                nomove[i].append(index)
    for i, allpos in enumerate(nomove):
        if not allpos:
            A[i] = sorted(A[i])[::-1]
            #print('no cube')
            continue
        #print(allpos,'\n')
        prev = -1
        for pos in allpos:
            A[i] = A[i][:prev+1] + sorted(A[i][prev+1:pos])[::-1] + A[i][pos:]
            prev = pos
        if prev != -1:
            A[i] = A[i][:prev+1] + sorted(A[i][prev+1:])[::-1]
    return A

# part 1

p1 = [ list(_) for _ in reversed(list(zip(*p1)))]
p1 = RollingLeft(p1)
for i, n in enumerate(list(zip(*p1))): r1 += n.count('O') * (len(p1) - i)

print("part 1:", r1)
assert(r1 in [113078,106648, 136])

# part 2

cc=1000000000

def Cycle(A):

    # 1 - NORTH --> 90 deg counter clockwise, roll left, 90 deg clockwise to get back
    A = [ list(_) for _ in reversed(list(zip(*A)))]
    A = RollingLeft(A)
    A = [list(_)for _ in list(zip(*reversed(A)))]

    # 2 - WEST
    A = RollingLeft(A)

    # 3 - SOUTH --> 90 deg clockwise, roll, 90 deg counter CW to get back
    A = [list(_)for _ in list(zip(*reversed(A)))]
    A = RollingLeft(A)
    A = [ list(_) for _ in reversed(list(zip(*A)))]

    # 4 - EAST --> twice 90 deg counter clockwise, roll, twice 90 deg CW to get back
    A = [ list(_) for _ in reversed(list(zip(*A)))]
    A = [ list(_) for _ in reversed(list(zip(*A)))]
    A = RollingLeft(A)
    A = [list(_)for _ in list(zip(*reversed(A)))]
    A = [list(_)for _ in list(zip(*reversed(A)))]
    #dbg(A)
    return A

S=set()
ALL=[p2]
state=''.join([''.join(r)for r in p2])
S.add(state)
t=None
for _ in range(1,cc+1):
    p2 = Cycle(p2)
    state=''.join([''.join(r)for r in p2])
    if state in S:
        t = _
        break
    S.add(state)
    ALL.append(p2)
if not t: print('something\'s wrong')

start = ALL.index(p2)
sizeof = t - start
offset = (cc - start) % sizeof

p2 = ALL[start + offset]
p2 = [ list(_) for _ in reversed(list(zip(*p2)))]
for i, n in enumerate(list(zip(*p2))): r2 += n.count('O') * (len(p2) - i)

print("part 2:", r2)
assert(r2 in [94255, 87700, 64])

