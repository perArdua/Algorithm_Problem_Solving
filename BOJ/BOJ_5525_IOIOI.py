from sys import stdin
import re
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

n = int(input())
m = int(input())

s = re.sub('OO+', ' ', input().rstrip())
s = re.sub('II+', 'I I', s)
res = 0
for x in map(lambda e: (len(e) - 1) // 2, s.split()):
    if x >= n: res += x + 1 - n
print(res)