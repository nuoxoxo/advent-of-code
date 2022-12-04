a = []
# with open('test') as file:
with open('2204.0') as file:
    for l in file:
        a.append(l.strip())
res1 = 0
res2 = 0
for n in a:
    aa = n.split(',')
    iv = []
    for i in range(2):
        iv.append(aa[i].split('-'))
    # print(iv)
    l, r = int(iv[0][0]), int(iv[0][1])
    ll, rr = int(iv[1][0]), int(iv[1][1])
    # print(l, r, ll, rr)
    if (l <= ll and r >= rr) or (ll <= l and rr >= r):
        # print(n)
        res1 += 1
    if r >= ll and l <= rr:
        res2 += 1

print('Star 1:', res1)
print('Star 2:', res2)
