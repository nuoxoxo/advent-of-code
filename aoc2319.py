F = 0
r1, r2 = 0, 0
A = []
from collections import defaultdict
import math # part 2
def DBG_( Dict ):
    for k,v in Dict.items(): print(k,v)
    print()
def Printer(*args):
    for arg in args: print(arg, end=' ')
    print('')

D = defaultdict(list)
flow, todo, up, down = [],[],None,None

with open('19.' + str(F)) as file:
    up, down = [_.split('\n') for _ in file.read().strip().split('\n\n')]

#up = ['ex{x>10:one,m<20:two,a>30:R,A}']
for line in up:
    name, rules = line.split('{')
    rules = rules.split(',')
    end, rules = rules[-1][:-1], rules[:-1]
    # Printer('got:',name,end,'rules:',len(rules),rules)
    for rule in rules:
        cond, dest = rule.split(':')
        key, op, val = cond[0],cond[1],int(cond[2:])
        # Printer("rule:",key,op,val,dest)
        D[name].append([ key, op, val, dest ])
    D[name].append(end)

DBG_( D )

for line in down:
    flow = defaultdict(int)
    line = line[1:-1].split(',')
    for xpr in line:
        key, val = xpr.split('=')
        flow[key] = int(val)
    res = None
    curr = 'in'
    found = False
    while not found:
        for line in D[curr]:
            good = False
            if isinstance(line, str):
                if line in 'AR':
                    res = line
                    found = True
                    break
                curr = line
            else:
                key, op, val, dest = line
                if op == '>':
                    good = flow[key] > val
                elif op == '<':
                    good = flow[key] < val
                else:
                    die('wtf')
            if good:
                if dest in 'AR':
                    res = dest
                    found = True
                    break
                curr = dest
                break
            
    if found and res == 'A':
        r1 += sum(flow.values())

Printer("part 1:", r1)

# Part 2

instructions = [
    ('in', [range(1,4001)] * 4)
]

AC = 0

while instructions :

    inst = instructions.pop(0)
    curr, rangex4 = inst

    if curr in 'AR':
        if curr == 'A': # case: R/ do nothing and pass; A/ add :in all combinations
            lengths = [len(_) for _ in rangex4]
            lengths_product = 1
            for n in lengths: lengths_product *= n
            AC += lengths_product
        continue

    *conditions, endpoint = D[curr]

    for key, op, val, dest in conditions:
        idx = 'xmas'.index(key)
        _range = rangex4[ idx ]
        if val not in _range:
            continue
        # split in half
        # make a range Object (1/2): prepare 2 slice each of which: [2]int
        L,R = [None]*2, [None]*2
        if op == '>':
            L = [ _range.start, val + 1 ]
            R = [ val + 1, _range.stop ]
            L,R = R,L
        elif op == '<':
            L = [ _range.start, val ]
            R = [ val, _range.stop ]
        else:
            die('wtf')
        # create a range object (2/2) : L and R are now objects of type range
        idx = 'xmas'.index(key)
        L, R = range(*L),range(*R)
        updated_range_x4 = [_ for _ in rangex4]
        updated_range_x4[idx] = L
        instructions.append( (dest, updated_range_x4) )
        rangex4[idx] = R
    instructions.append ( (endpoint, rangex4) )

r2 = AC

Printer("part 2:", r2)
assert(r1 in [19114, 353553])
assert(r2 in [124615747767410, 167409079868000])

