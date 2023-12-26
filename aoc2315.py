F = 0
r1, r2 = 0, 0
A = []
with open('15.' + str(F)) as file: line = file.read()

# part 1

def hashing(a)->int:
    res = 0
    for c in a:
        res = (res + ord(c)) * 17 % 256
    return res

A=line.strip().split(',')
for a in A: r1 += hashing(a)

print("part 1:", r1)

# part 2

B = [ [] for _ in range(256)]
for a in A:
    if '-' in a:
        key = a[:-1]
        print(key,a)
        hsh = hashing(key)
        found = False
        for sub in B[hsh]:
            if sub[0] == key:
                found = True
        if found:
            temp = []
            for sub in B[hsh]:
                if sub[0] != key:
                    temp.append(sub)
            B[hsh] = temp
    elif '=' in a:
        key, leng = a.split('=')
        hsh = hashing(key)
        leng = int(leng)
        found = False
        for sub in B[hsh]:
            if sub[0] == key:
                found = True
        if not found:
            B[hsh].append([key, leng])
        else:
            for sub in B[hsh]:
                if sub[0] == key:
                    sub[1] = leng
for i,sub in enumerate(B):
    for slot, kv in enumerate(sub):
        r2 += (i + 1) * (slot + 1) * kv[1]

print("part 2:", r2)


