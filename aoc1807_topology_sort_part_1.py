from collections import defaultdict, deque

words = [] # for test

E = defaultdict(list)
P = defaultdict(int) # how many paths to a node, or edges a node has, (one way)

for line in open('1807.1'):
    tmp = line.split()
    words.append(tmp) # for test
    L = tmp[1]
    R = tmp[7]
    E[L].append(R)
    P[R] += 1 # ?

"""
for w in words:
    print(w)
"""

print(E, P, sep='\n')

Q = []
for key in E: # loop on keys
    print(key, E[key])
    if P[key] == 0: # find the one w/o any edg to it, it goes first
        Q.append(key)

print(Q)

r = ""

while Q:
    node = sorted(Q)[0] # new step
    r += node
    Q = [_ for _ in Q if _ != node] # the rest from new queue
    for n in E[node]: # traverse all paths beginning from this node
        P[n] -= 1 # countdown, 0 means this node n is free and can go
        if P[n] == 0:
            Q.append(n)

print("star 1: ", r)
