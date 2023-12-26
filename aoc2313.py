F = 0
r1, r2 = 0, 0
A = []
def dbg(T):
    for t in T:print(t)
with open('13.' + str(F)) as file:
    temp = []
    for bloc in file:
        bloc=bloc.strip()
        if not bloc:
            A.append(temp)
            temp = []
        else:
            temp.append([_ for _ in bloc])
    if temp:
        A.append(temp)
# dbg(A)
for bloc in A:
    p2 = True
    def horver(bloc, p2=False): # yield either row index or col index
        idx = 0
        for i in range(1, len(bloc)):
            diff = 0
            u, d = i - 1, i
            busted = False
            while u > -1 and d < len(bloc):
                for U, D in zip(bloc[u], bloc[d]):
                    if U != D:
                        diff += 1
                    if diff > 1:
                        busted = True
                        break
                if busted:
                    break
                u -= 1
                d += 1
            if not p2 and diff == 0 or p2 and diff == 1:
                idx = i
                break
        return idx
    tb = [_ for _ in zip(*bloc)] # transpose
    lhs = horver(bloc)
    rhs = horver(tb)
    print('p1:', lhs, rhs)
    r1 += lhs * 100 + rhs
    lhs = horver(bloc,p2)
    rhs = horver(tb,p2)
    r2 += lhs * 100 + rhs
    print('p2:', lhs, rhs)

print("Part 1:", r1)
assert(r1==37975)
print("Part 2:", r2)
assert(r2==32497)

