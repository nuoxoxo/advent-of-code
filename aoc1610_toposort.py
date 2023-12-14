F = 0
r1, r2 = 0, 0
import re
from collections import defaultdict
BOT=defaultdict(list)
OUT=defaultdict(list)
inst={}#defaultdict(list)

with open('10.' + str(F)) as file:
    for line in file:
        line=line.strip()
        if 'value' in line[:6]:
            # val, bot = map(int,re.findall(r'\d+', line))
            val, bot = [int(_) for _ in re.findall(r'\d+', line)]
            BOT[bot].append(val)
            #print(bot, val)
        if 'bot' in line[:6]:
            regex = r'bot (\d+) gives low to (\w+) (\d+) and high to (\w+) (\d+)'
            bot, bo1, ref1, bo2, ref2 = re.findall(regex, line)[0]# BO: bot or output
            inst[int(bot)] = [bo1, int(ref1), bo2, int(ref2)]
            #print([int(bot),bo1,int(ref1),bo2,int(ref2)])
for k,v in BOT.items(): print('bot?:',k,v)
r1 = None
while BOT:
    for bot, n in list(BOT.items()):
    # for bot, n in [_ for _ in BOT.items()]:
        if len(n) == 2: # the 1st one is bot 12 output [73, 41]
            lo, hi = sorted(BOT.pop(bot))
            #print(lo, hi)
            if lo == 17 and hi == 61:
                r1 = bot
                #print(bot)
            bo1, ref1, bo2, ref2 = inst[ bot ]
            if bo1 == 'output':
                OUT[ref1].append(lo)
            elif bo1 == 'bot':
                BOT[ref1].append(lo)
            if bo2 == 'output':
                OUT[ref2].append(hi)
            elif bo2 == 'bot':
                BOT[ref2].append(hi)
r2 = OUT[0][0] * OUT[1][0] * OUT[2][0]
print('part 1:', r1)
print('part 2:', r2)
