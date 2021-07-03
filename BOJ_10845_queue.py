from sys import stdin
from collections import deque

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())


dq = deque()
ans = []
for _ in range(int(input())):
    s = input().rstrip().split()
    if s[0] == 'pop':
        ans.append(dq.popleft() if dq else -1)
    elif s[0] == 'size':
        ans.append(len(dq))
    elif s[0] == 'empty':
        ans.append(0 if dq else 1)
    elif s[0] == 'front':
        ans.append(dq[0] if dq else -1)
    elif s[0] == 'back':
        ans.append(dq[-1] if dq else -1)
    else:
        dq.append(s[-1])
print(*ans, sep='\n')