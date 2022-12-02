from typing import List

# a = [_.strip() for _ in open('test')]

a = [_.strip() for _ in open('2003.0')]

def treecount(a: List[str], r: int, d: int) -> int:
    res = 0
    i, j = 0, 0
    while i < len(a):
        if a[i][j] == '#':
            res += 1
        j += r
        if j + r > len(a[i]) - 1:
            j %= len(a[i])
        i += d
    return res

r = treecount(a, 3, 1)
rr = r
rr *= treecount(a,1,1) * treecount(a,5,1) * treecount(a,7,1) * treecount(a,1,2)
print("Star 1:", r)
print("Star 2:", rr)
