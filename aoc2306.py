F = 0
from collections import defaultdict 
r1, r2 = 1,1
A,Z,T,D=[],[],[],[]
with open('06.' + str(F)) as file:
    tmp = []
    for line in file:
        line=[int(_)for _ in line.strip().split(':')[1].split()]
        A.append(line)
        Z.append(''.join([str(_)for _ in line]))
T,D=A
best=0
tt,ttt=[],[]
for t,d in zip(T,D):
    times=0
    for i in range(t):
        res = (t - i) * i
        if res > d:
            times+=1
    tt.append(times)
for t in tt:
    r1*=t
print('part1?',r1,'\n')
# part 2
Z=[int(_)for _ in Z]
t,d = Z
times=0
for i in range(t):
    res = (t - i) * i
    if res > d:
        times+=1
ttt.append(times)
for t in ttt:
    r2*=t
print('part 1:', r1)
print('part 2:', r2)
