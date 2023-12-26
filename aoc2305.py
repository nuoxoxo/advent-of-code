F = 0
from collections import defaultdict 
r1, r2 = 0, 0
A,sds=[],[]
D=[]
with open('05.' + str(F)) as file:
    tmp = []
    for line in file:
        line=line.strip()
        if 'seeds' in line:
            sds = [int(_) for _ in line.split(':')[1].split()]
            continue
        if not line and tmp:
            A.append(tmp)
            tmp = []
            continue
        if line: tmp.append(line)
    A.append(tmp)
ss = sds.copy() ## for part 2
# part 1
for a in A:
    tmp = [_.split() for _ in a[1:]]
    temp = []
    for r in tmp:
        r.reverse()
        rr = [int(_) for _ in r]
        temp.append(rr)
    D.append(temp)
#for _ in D:print('d:',_)
for d in D:
    for i in range(len(sds)):
        sd = sds[i]
        for size, begin, end in d:
            if sd in range(begin, begin + size):
                goto = sd - begin + end
                sds[i] = goto
                break
r1 = min(sds)
# part 2
tmp = []
for i in range(0, len(ss), 2):
    tmp.append((ss[i], ss[i]+ss[i+1]))
ss = tmp
for d in D:
    tmp = []
    while len(ss) > 0:
        l, r = ss.pop() # left & right bound
        found = False
        for size, begin, end in d:
            L = max(l, begin) # real shrunk L, R bounds 
            R = min(r, begin + size)
            if L < R:
                tmp.append( (L - begin + end, R - begin + end) )
                if L > l:
                    ss.append( (l, L))
                if r > R:
                    ss.append( (R, r))
                found = True
                break
        if not found:
            tmp.append((l, r))
    ss = tmp
print("part 1:", r1)
print("part 2:", sorted(ss)[0][0])
