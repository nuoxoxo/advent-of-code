facing = 0
dx = [ 0, 1, 0, -1]
dy = [-1, 0, 1,  0]
x, y = 0, 0
E = set()
ok = False
for s in input().strip().split(', '):
    if s[0] == 'L':
        facing = (facing + 3) % 4
    if s[0] == 'R':
        facing = (facing + 1) % 4
    dist = int(s[1:])

    # Part 2 logic starts
    if dy[facing] == 0:
        n = 1 if dx[facing] > 0 else -1
        for i in range(n + x, n + x + dx[facing] * dist, n):
            if (i,y) not in E:
                E.add((i,y))
            else:
                if ok is False:
                    first = (i,y)
                    ok = True
    else:
        n = 1 if dy[facing] > 0 else -1
        for i in range(n + y, n + y + dy[facing] * dist, n):
            if (x,i) not in E:
                E.add((x,i))
            else:
                if ok is False:
                    first = (x,i)
                    ok = True
    # ends

    x += dx[facing] * dist
    y += dy[facing] * dist

p1 = abs(x) + abs(y)
p2 = abs(first[0]) + abs(first[1])
print(p1)
print(p2)
