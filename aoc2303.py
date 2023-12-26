tst = 0
# 541497 545250 545808 too hi - p1
r1, r2 = 0, 0
a = []
with open('03.' + str(tst)) as file:
    for line in file:
        a.append(line[:-1])
R, C = len(a), len(a[0])
T = []
num = ''
for r in range(R):
    num = ''
    coor = []
    for c in range(C):
        ch = a[r][c]
        if ch.isdigit():
            if not coor:
                coor = [r, c]
            num += ch
        elif num != '':
            T.append([[coor, [r, c - 1]], int(num), False])
            coor = []
            num = ''
    if num != '':
        T.append([[coor, [r, C - 1]], int(num), False])
        coor = []
        num = ''
print(T)
for r in range(R):
    num = ''
    coor = []
    for c in range(C):
        ch = a[r][c]
        if ch == '*': ## p2
            pset = set()
            for rr in range(r - 1, r + 2):
                for cc in range(c - 1, c + 2):
                    if -1<rr<R and -1<cc<C:
                        for t in T:
                            head, tail = t[0][0], t[0][1]
                            if head == [rr, cc] or tail == [rr, cc]:
                                pset.add( (head[0], head[1], tail[0], tail[1], t[1]) )
            if len(pset) == 2:
                lp = list(pset)
                r2 += lp[0][4] * lp[1][4]
        ## p1 
        if ch.isdigit() or ch == '.':
            continue
        for rr in range(r - 1, r + 2):
            for cc in range(c - 1, c + 2):
                if -1<rr<R and -1<cc<C:
                    for t in T:
                        if t[0][0] == [rr, cc] or t[0][1] == [rr, cc]:
                            t[2] = True
r1 += sum(t[1] if t[2] else 0 for t in T)
print("part 1:", r1)
print("part 2:", r2)

