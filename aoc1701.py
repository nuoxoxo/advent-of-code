#* ******************************************** *#
#*                                              *#
#*              \\             /`/``            *#
#*              ~\o o_       0 0\               *#
#*              / \__)      (u  ); _  _         *#
#*       / \/ \/  /           \  \/ \/ \        *#
#*      /(   . . )            (         )\      *#
#*     /  \_____/              \_______/  \     *#
#*         []  []               [[] [[]    *.   *#
#*         []] []]              [[] [[]         *#
#*                                              *#
#* ************************************ nuo *** *#

s = input()
i = 0
p1 = 0
p2 = 0
while i < len(s):
    if i > 0:
        if i == len(s) - 1 and s[i] == s[-1]:
            p1 += int(s[-1])
        if s[i] == s[i - 1]:
            p1 += int(s[i])
    half = i+len(s)//2 if i<len(s)//2 else i-len(s)//2
    if s[i] == s[half]:
        p2 += int(s[i])
    i += 1
print(p1)
print(p2)
