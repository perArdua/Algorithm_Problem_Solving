import sys
from collections import defaultdict
from functools import cmp_to_key
input = sys.stdin.readline
MIS = lambda : map(int, input().rstrip().split())

n, m = MIS()
voca = defaultdict(lambda:0)
sor = [[] for _ in range(n + 1)]
for _ in range(n):
    tmp = input().rstrip()
    if len(tmp) >= m:
        voca[tmp] += 1

for key in voca.keys():
    sor[voca[key]].append(key)

def cmp(x, y):
    len_x, len_y = len(x), len(y)
    if len_x == len_y:
        return 1 if x > y else 0 if x == y else -1
    return 1 if len_x < len_y else -1

for data in sor[::-1]:
    if data:
        if len(data) > 1:
            res = sorted(data, key=cmp_to_key(cmp))
            print(*res, sep='\n')
        else:
            print(*data)
