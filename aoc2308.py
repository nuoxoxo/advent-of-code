F = 0
# 56922302683x . 2084338078790969416800 : hi
import math
r1, r2 = 0, 0
A,P=[],''
ok=False
with open('08.' + str(F)) as file:
    for line in file:
        line=line.strip()
        if line == '':
            ok=True
        elif not ok:
            P=line
        else:
            A.append(line)
L,R={},{}
D={}#,counter={},{}#defaultdict(str)#{}
t=0
plen= len(P)
for a in A:
    node, tmp = a.split('=')
    l,r = tmp.split(', ')
    node,l,r = node[:-1], l[2:], r[:-1]
    print(node,'>',l,r)
    """if 'L' not in D:
        D['L']={}
    if 'R' not in D:
        D['R']={}"""
    L[node],R[node] = l,r
#print('P:',P)
#for a in A:print(a)

# part 1
node = 'AAA'
while not node == 'ZZZ':
    DIR = P[t % plen]
    if DIR == 'L':
        node = L[node]
    else:
        node = R[node]
    t += 1
r1 = t

# part 2
A = []
counter = {}
for node in L: # L and R have same set of Keys
    if node[-1] == 'A':
        A.append(node)
t = 0
Rec = []
while 1:
    Nodes = []
    found = False
    for i in range(len(A)):
        node = A[i]
        DIR = P[t % plen]
        if DIR == 'L':
            node = L[node]
        else:
            node = R[node]
        if node[-1] == 'Z':
            counter[i] = t + 1
            if len(counter) == len(A): # all the A paths have been completed
                found = True
                tmp = [v for k,v in counter.items()]
                res = 1
                for v in tmp:
                    gcd = math.gcd(res, v)
                    res = res * v // gcd
                Rec, r2 = tmp, res
                break
        Nodes.append(node)
    if found:
        break
    A = Nodes.copy()
    t += 1
print('part 1:', r1)
print('part 2:', r2, counter)


