F = 0
#//////////////////////////////////////////////////
#//              part 2 pending                  //
#//////////////////////////////////////////////////
r1, r2 = 0, 0
lines = []
import math
with open('20.' + str(F)) as file:
    for line in file:lines.append(line.strip())
def dbg( Thing, *names ):
    if names:
        for name in names: print(name, end=' ')
    if isinstance(Thing, str): print(Thing)
    if isinstance(Thing, dict):
        Dict = Thing
        print(Dict)
        for k,v in Dict.items(): print(k,v)
    if isinstance(Thing, list):
        things = Thing
        print(things)
        for thing in things: print( thing )
    print()

BC = []
FF,CJ= {},{}#,{}
sep='-'*6

for line in lines:
    key, val = line.split(' -> ')
    val = val.split(', ')
    print(key,val,'from/',line)
    if 'broadcast' in key:
        BC = val
    symbol, key = key[0], key[1:]
    if symbol == '%':
        FF[ key ] = val
    if symbol == '&':
        CJ[ key ] = val

FFCJ = FF | CJ # dict(ff, **cj)
dbg( BC, 'BC/'),dbg(FF,'FF/'),dbg(CJ,'CJ/')
dbg( FFCJ, 'FFCJ/' )
T = 1000
sent_signals = [T, 0]

CJ_find_wayback = dict()
for conj in CJ:
    CJ_find_wayback[conj] = {}
    for k, v in FFCJ.items():
        if conj in v:
            CJ_find_wayback[conj][k] = 0# = {k: 0}
dbg(CJ_find_wayback, 'CJ_find_wayback')

CJ_with_pulse = []#{}

for _ in range( T ):
    TODO = [('broadcaster', 0, signal) for signal in BC]#['broadcaster']]
    #dbg(TODO)
    while TODO:
        src, pulse, curr = TODO.pop(0)
        # print('--->',pulse,'<---')
        #print(src, curr)
        sent_signals[pulse] += 1
        if curr not in FFCJ:
            continue
        destlist = FF[curr] if curr in FF else CJ[curr]
        if curr in FF and pulse == 0:
            for dest in destlist:
                job = None
                if curr in CJ_with_pulse:
                    job = ( curr, 0, dest )
                else:
                    job = ( curr, 1, dest )
                TODO.append( job )

        if curr in CJ:
            CJ_find_wayback[curr][src] = pulse
            if pulse == 1 and len(CJ_find_wayback[curr]) == 1:
                next_pulse = 0
            elif all(v for v in CJ_find_wayback[curr].values()):
                next_pulse = 0
            else:
                next_pulse = 1
            for dest in destlist:
                job = ( curr, next_pulse, dest )
                TODO.append(job)
        if src in FF:
            if pulse == 1:#pulse:#pulse == 0:#pulse:
                CJ_with_pulse.append( src )
            else:
                CJ_with_pulse.remove( src )
        #dbg (CJ_with_pulse, 'cj pulse count/')

r1 = math.prod(sent_signals)

print("part 1:", r1)
print("part 2:", r2)


