t = 0
r1 = 0
r2 = 0
D = {'red':12, 'green':13, 'blue':14}
with open('02.' + str(t)) as file:
    A, I = [], []
    idx = 1
    for line in file:
        line = line[:-1]
        R = line.split(':')[1:][0].split()
        ok = True
        for i in range(0, len(R), 2):
            w = R[i + 1]
            if w[-1] in [',', ';']:
                w = w[:-1]
            v = int(R[i])
            k = w
            if D[k] < v:
               ok = False
        if ok:
            r1 += idx
        R, B, G = 0, 0, 0
        rr = line.split(':')[1].split(';')
        for el in rr:
            e = el.split()
            for i in range(0, len(e), 2):
                v, k = int(e[i]), e[i + 1]
                if 'red' in k:
                    R = max(R, v)
                if 'blue' in k:
                    B = max(B, v)
                if 'green' in k:
                    G = max(G, v)
        r2 += R * B * G
        print(R, G, B, R*G*B, r2)
        idx += 1
print("part 1:", r1)
print("part 2:", r2)
