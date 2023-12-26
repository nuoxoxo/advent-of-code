F = 0 # hi : 1251 - p2 hi : 1093
r1, r2 = 0, 0
A = []
AA=[]
def dbg(T):
    for t in T:print(' '.join([str(_)for _ in t]))
import heapq
from collections import defaultdict
with open('17.' + str(F)) as file:
    for line in file:
        A.append([int(_)for _ in line.strip()])

def min_loss2(A) -> int:
    R, C = len(A), len(A[0])
    DR = [1,0,-1, 0]
    DC = [0,1, 0,-1]
    loss = None
    S = { (0, 0, (0, 0, 0, 0)) }
    east = ( 0, 0, (0, 0, 0, 1) )
    south = ( 0, 0, (0, 0, 1, 0) )
    Q = [ east, south ]
    heapq.heapify( Q )
    while Q:
        loss, step, D = heapq.heappop( Q )
        r, c, dr, dc = D
        if r < 0 or r > R - 1 or c < 0 or c > C - 1: continue
        if r == R - 1 and c == C - 1 and step > 3:return loss#break
        if (step, D) in S: continue
        S.add( (step, D) )
        if step > 9:
            step = 1
            for rr, cc in zip(DR, DC):
                if rr == dr and cc == dc or rr == -dr and cc == -dc: continue
                newr, newc = r + rr, c + cc
                if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
                    newloss = loss + A[newr][newc]
                    heapq.heappush( Q, ( newloss, step, ( newr, newc, rr, cc ) ) )
            continue
        newr, newc = r + dr, c + dc
        # continue current dir
        if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
            newloss = loss + A[newr][newc]
            heapq.heappush( Q, ( newloss, step + 1, ( newr, newc, dr, dc ) ) )
        # move sideways
        if step > 3:
            step = 1
            for rr, cc in zip(DR, DC):
                if rr == dr and cc == dc or rr == -dr and cc == -dc: continue
                newr, newc = r + rr, c + cc
                if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
                    newloss = loss + A[newr][newc]
                    heapq.heappush( Q, (newloss, step, ( newr, newc, rr, cc ) ) )

def min_loss(A) -> int:
    R, C = len(A), len(A[0])
    DR = [1, 0, -1,  0]
    DC = [0, 1,  0, -1]
    dbg(A)
    loss = None
    S = { (0, 0, (0, 0, 0, 0)) }
    east = ( 0, 0, (0, 0, 0, 1) )
    south = ( 0, 0, (0, 0, 1, 0) )
    Q = [ east, south ]
    heapq.heapify( Q )
    while Q:
        loss, step, D = heapq.heappop( Q )
        r, c, dr, dc = D
        if r < 0 or r > R - 1 or c < 0 or c > C - 1: continue
        if r == R - 1 and c == C - 1:return loss#break
        if (step, D) in S: continue
        S.add( (step, D) )
        if step > 2:
            step = 1
            for rr, cc in zip(DR, DC):
                if rr == dr and cc == dc or rr == -dr and cc == -dc: continue
                newr, newc = r + rr, c + cc
                if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
                    newloss = loss + A[newr][newc]
                    heapq.heappush( Q, ( newloss, step, ( newr, newc, rr, cc ) ) )
            continue
        newr, newc = r + dr, c + dc
        # continue current dir
        if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
            newloss = loss + A[newr][newc]
            heapq.heappush( Q, ( newloss, step + 1, ( newr, newc, dr, dc ) ) )
        # move sideways
        step = 1
        for rr, cc in zip(DR, DC):
            if rr == dr and cc == dc or rr == -dr and cc == -dc: continue
            newr, newc = r + rr, c + cc
            if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
                newloss = loss + A[newr][newc]
                heapq.heappush( Q, (newloss, step, ( newr, newc, rr, cc ) ) )
    # 
    # i know where the bug is : checking all next 3x3 steps in a roll 
    # does not count say a sudden turn like Rx1 Dx2 or U-R-U 
    # or the very first step being moving south
    """
    Q = [(A[0][0], (0, 0, 0, 1)), (A[0][0], (0, 0, 1, 0))] # val, (r, c, dir)
    heapq.heapify(Q)
    # possible = []
    M = defaultdict(list)
    M = defaultdict( lambda: 1e9)
    M[(0, 0)] = A[0][0]
    while Q:
        loss, D = heapq.heappop(Q)
        # r, c, dc, dr = D # 90 turn
        r, c, dr, dc = D
        if r < 0 or r > R - 1 or c < 0 or c > C - 1: continue
        if r == R - 1 and c == C - 1:return loss#break
        # if (loss, D) in S: continue
        if D in S: continue
        S.add((r,c,dr,dc))
        for step in range(1,4):
            newr = r + dr * step
            newc = c + dc * step
            if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
                newloss = loss + A[newr][newc]
                #print(newloss, newr, newc, R, C)
                # M[(newr,newc)] = min(M[(newr, newc)], newloss)
                heapq.heappush( Q, (newloss, (newr, newc, dr, dc)) )
                print('U:',newr,newc,loss)
        dr, dc = dc, dr # 90 turn
        for step in range(1,4):
            for t in [-1, 1]:
                newr = r + dr * step * t
                newc = c + dc * step * t
                if not (newr < 0 or newr > R - 1 or newc < 0 or newc > C - 1):
                    newloss = loss + A[newr][newc]
                    heapq.heappush( Q, (newloss, (newr, newc, dr, dc)) )
                print('D:',newr,newc, loss)
    """
    #print(min(M[(R-1, C-1)]))
    #print(M[(R - 1, C - 1)])
    #print(loss)
    return loss
        
r1=min_loss(A)
r2=min_loss2(A)

print("part 1:", r1)
print("part 2:", r2)
assert(r1 in [102, 1246, 59])
assert(r2 in [94, 1389, 71])
