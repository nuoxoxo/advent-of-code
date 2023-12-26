lines = open(0).read().strip().split('\n')
#print(lines, len(lines))

SIG = 2 ** 16 - 1
def solve (part2=False):
    D = {}
    CMD = lines.copy()
    while CMD:
        for i, line in enumerate(CMD):
            # print(expr, val)
            def getter (val):
                if val.isdigit():
                    return int(val)
                if part2 and val == 'b': # Part 2
                    return part2
                return D[val]
            def parser (expr):
                EXP = expr.split()
                if len(EXP) == 1:
                    return getter(EXP[0])
                if EXP[0] == 'NOT':
                    val = getter(EXP[1])
                    return SIG ^ val
                if len(EXP) > 3:
                    assert False
                L, op, R = EXP
                L, R = getter(L), getter(R)
                if op == 'LSHIFT':
                    return L << R
                if op == 'RSHIFT':
                    return L >> R
                if op == 'AND':
                    return L & R
                if op == 'OR':
                    return L | R
                assert False
            expr, val = line.split(' -> ')
            #print(val, expr)
            try:
                D[val] = parser(expr)
                del CMD[i]
            except KeyError:
                continue
    return D
    """
    if not part2:
        return D
    CMD = lines.copy()
    part1 = D['a']
    D = {}
    while CMD:
        for i, line in enumerate(CMD):
            # print(expr, val)
            def getter (val):
                if val.isdigit():
                    return int(val)
                if val == 'b':
                    return part1
                return D[val]
            def parser (expr):
                EXP = expr.split()
                if len(EXP) == 1:
                    return getter(EXP[0])
                if EXP[0] == 'NOT':
                    val = getter(EXP[1])
                    return SIG ^ val
                if len(EXP) > 3:
                    assert False
                L, op, R = EXP
                L, R = getter(L), getter(R)
                if op == 'LSHIFT':
                    return L << R
                if op == 'RSHIFT':
                    return L >> R
                if op == 'AND':
                    return L & R
                if op == 'OR':
                    return L | R
                assert False
            expr, val = line.split(' -> ')
            #print(val, expr)
            try:
                D[val] = parser(expr)
                del CMD[i]
            except KeyError:
                continue
    return D
    """
part1 = solve()['a']
print('part 1:', part1)
print('part 2:', solve( part1 )['a'])

