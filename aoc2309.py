F = 0
r1, r2 = 0, 0
with open('09.' + str(F)) as file:
    for line in file:
        line=line.strip()
        a = [[int(_)for _ in line.split()]]
        def expl(a):
            while a[-1].count(0) != len(a[-1]):
                temp = []
                for i in range(1, len(a[-1])):
                    temp.append(a[-1][i] - a[-1][i-1])
                a.append(temp)
            return a
        a = expl(a)
        # part 1
        for aa in a:
            r1 += aa[-1]
        # part 2
        tmp = 0
        for aa in a[::-1]:
            tmp = aa[0] - tmp
        r2 += tmp

print('part 1:', r1)
print('part 2:', r2)

