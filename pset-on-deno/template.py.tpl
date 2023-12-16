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

