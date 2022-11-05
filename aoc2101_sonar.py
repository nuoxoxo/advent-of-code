d = []
for line in open('../input/2101.0'):
    d.append(int(line))
p1, p2 = 0, 0
for i in range(len(d)):
    if i > 0:
        if d[i] > d[i - 1]:
            p1 += 1
    if i > 2:
        t1 = d[i] + d[i - 1] + d[i - 2]
        t2 =        d[i - 1] + d[i - 2] + d[i - 3]
        if t1 > t2:
            p2 += 1
print('Star 1:', p1)
print('Star 2:', p2)
