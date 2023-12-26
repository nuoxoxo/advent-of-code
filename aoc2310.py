F=2
# 1092 . too hi
r1, r2 = 0, 0
A=[]
sp = []
with open('10.' + str(F)) as file:
    for line in file:
        line=line.strip()
        A.append(line)
print('\n'.join(A))
for r in range(len(A)):
    if 'S' in A[r]:
        for c in range(len(A[r])):
            if A[r][c] == 'S':
                sp.append((r,c))
assert(len(sp) == 1)
S = (sp[0][0],sp[0][1])
print('from:',sp)

# | - L J 7 F 
Go = ['J|L', '7|F', 'J-7', 'L-F'] # order : UDLR
Get= [Go[1], Go[0], Go[3], Go[2]]

D = [S]
seen = {S}
R, C = len(A), len(A[0])
print('seen:',seen)
print('bfs :',D)

SS={'-','|','7','F','L','J'} # Find what S is # part 2

dr=[-1, 1, 0, 0]
dc=[ 0, 0,-1, 1] # order : UDLR
while D:
    r, c = D.pop(0)
    pipcurr = A[r][c]
    for i in range(4):
        rr, cc = r + dr[i], c + dc[i]
        if (rr, cc) in seen or not (rr > -1 and rr < R and cc > -1 and cc < C):
            continue
        pipnext = A[rr][cc]
        #print('is legal move:', pipcurr, pipnext)
        if pipcurr in Go[i]+'S' and pipnext in Get[i]:
            seen.add((rr, cc))
            D.append((rr, cc))
            if pipcurr == 'S':
                SS &= set( Go[i] + 'S' ) # Find pipe in S
print(seen)
r1 = len(seen) // 2

# part 2
A[sp[0][0]] = A[sp[0][0]].replace('S', list(SS)[0])
for r in range(R):
    for c in range (C):
        if (r, c) not in seen:
            A[r] = A[r][:c] + '.' + A[r][c + 1:]
OUT = set()
for r in range(R):
    inside = False
    upward = None
    for c in range(C):
        pipcurr = A[r][c]
        #if pipcurr == '-': pass
        if pipcurr == '|': inside = not inside
        elif pipcurr == 'L': upward = True # face up and ----> 
        elif pipcurr == 'F': upward = False# face down + ---->
        elif upward and pipcurr == '7':
            inside = not inside
        elif not upward and pipcurr == 'J':
            inside = not inside

        """elif pipcurr == 'J':
            if not upward: inside = not inside
        elif pipcurr == '7':
            if upward: inside = not inside
        """
        if not inside: OUT.add( (r, c) )

IN = OUT | seen
r2 = R * C - len(IN)

print('part 1:', r1, f'; S is {SS}')#, list(SS)[0], A[sp[0][0]][sp[0][1]])
print('part 2:', r2)

assert(r1 in [4,8,6947,6947*2, 6697])
assert(r2 in [273, 423])


