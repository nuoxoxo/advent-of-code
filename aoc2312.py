F=0
r1, r2 = 0, 0 #None
A=[]
with open('12.' + str(F)) as file:
    for line in file:
        line=line.strip()
        L,R=line.split()
        A.append([L,[int(_) for _ in R.split(',')]])

# - ???.### 1,1,3 - 1 arrangement
# - .??..??...?##. 1,1,3 - 4 arrangements
# - ?#?#?#?#?#?#?#? 1,3,1,6 - 1 arrangement
# - ????.#...#... 4,1,1 - 1 arrangement
# - ????.######..#####. 1,6,5 - 4 arrangements
# - ?###???????? 3,2,1 - 10 arrangements
from functools import lru_cache
@lru_cache(maxsize=None)
def DFS(line, resource, pt=None):
    if not line or all(_ == '.' for _ in line):
        if resource:
            return 0 # line ends prematurely but still resources to consider
        print(pt, 'validated:', line, resource)
        return 1 # only valid case: IIF line is '' or '....' and no resources left
    if line[0] == '?': # Wildcard: to consider both possibilities
        OP = '.' + line[1:]
        # '?#?' >> '##?'  1)
        #       >> '.#?'  2)
        DM = '#' + line[1:]
        # '?.#' >> '#.#'  1)
        #       >> '..#'  2)
        return DFS(OP, resource, pt) + DFS(DM, resource, pt)
    if line[0] == '#':
        if not resource:
            return 0 # not enough resources but still some # left
        rcs = resource[0]
        if len(line) < rcs: # - '###' [4]
            return 0 # next resource exceeds the land we have
        if not all(_ in '#?' for _ in line[:rcs]): # - '#?.#??' (3,1)
            return 0 # no separator ('.') allowed in the next rcs chars
        if len(resource) == 1:
            return DFS(line[rcs:], resource[1:]) # mv to next even if next is nul
            # case is '##.?' [2]
            # will be '.?'   []
        if len(resource) > 1:
            if len(line) < rcs + 1:
                return 0 # not enough land for resources even after rcs used
            if line[rcs] == '#':
                return 0 # if enough land, a separator ('.') is needed 
            print(pt, 'move next:', line, resource)
            return DFS(line[rcs + 1:], resource[1:], pt) # mv to next and next is not nul
            # case is '##.?..' [2,1]
            # will be   '.?..' [1]
    if line[0] == '.':
        return DFS(line[1:], resource, pt) # mv to next validation a non-dot-filled line

for line, resource in A:
    resource = tuple(resource)
    r1 += DFS(line, resource, 1)
    # print('part 1:', r1)
for line, resource in A:
    resource = tuple(resource)
    r2 += DFS(((line + "?") * 5)[:-1], resource * 5, 2)
    # print('part 2:', r2)
print('part 1:', r1, '- final')
print('part 2:', r2, '- final')

