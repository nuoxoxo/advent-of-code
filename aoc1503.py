i=0
f=0
ok=False
for c in input().strip():
    f += 1
    i = i + 1 if c is '(' else i - 1
    if i < 0 and ok is False:
        p = f
        ok=True
print(i)
print(p)
