#* ******************************************** *#
#*                                              *#
#*              ~  ~  ~  ~  ~    ~              *#
#*               ~    _ ~ _   o>                *#
#*              ~  \ / \ / \ /  ~               *#
#*               ~  ~      ~    ~               *#
#*                                              *#
#* ******************************************** *#

import sys

E = []
lines = sys.stdin.read()
for line in lines.splitlines():
    words = line.split()
    pos, start = int(words[3]), int(words[-1][:-1])
    E.append((pos, start))

x = 0
while True:
    ALL = True
    for i, (pos, start) in enumerate(E):
        if (start + x + i + 1) % pos != 0:
            ALL = False
    if ALL is True:
        break
    x += 1

E.append((11, 0))
y = 0
while True:
    ALL = True
    for i, (pos, start) in enumerate(E):
        if (start + y + i + 1) % pos != 0:
            ALL = False
    if ALL is True:
        break
    y += 1

print("Star 1:", x)
print("Star 2:", y)
