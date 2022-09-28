d = []
for line in open('sonar.0'):
    d.append(int(line))
p1, p2 = 0, 0
for i in range(len(d)):
    if i > 0:
        if d[i] > d[i - 1]:
            p1 += 1
    if i > 2:
        if d[i] + d[i - 1] + d[i - 2] > d[i - 1] + d[i - 2] + d[i - 3]:
            p2 += 1
print('Star 1: ', p1)
print('Star 2: ', p2)
