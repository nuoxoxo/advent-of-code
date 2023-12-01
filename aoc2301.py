import re
import requests
import sys
import os

day = 1
session = os.getenv('AOC_SESSION')
print(session)
url = "https://adventofcode.com/2023/day/" + str(day) + "/input"
headers = {'Cookie': 'session=' + session}
resp = requests.get(url, headers = headers)
if resp.status_code != 200:
    sys.exit(f'{resp.status_code}\n{resp.reason}\n{resp.content}')
infile = resp.text
lines = infile.split('\n')
print(lines, 'len:', len(lines))
lines.pop()

r1 = 0
r2 = 0
   
D = {'one' : 1, 'two' : 2, 'three':3, 'four':4, 'five':5, 'six':6, 'seven':7, 'eight':8, 'nine':9, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '0':0}
A = []
for line in lines:
    n = re.findall(r'\d+', line)
    s = ''.join(n)
    ss = int(s[0] + s[-1])
    r1 += ss
    temp = []
    for w in D:
        first = line.find(w)
        last = line.rfind(w)
        if (first != -1):
            temp.append((first, w))
        if (last != -1): 
            temp.append((last, w))
    A.append(sorted(temp))
for a in A:
    L = str(D[a[0][1]])
    R = str(D[a[-1][1]])
    r2 += int(L + R)
print("Star 1:", r1)
print("Star 2:", r2)
