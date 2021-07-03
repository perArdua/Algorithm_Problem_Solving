from sys import stdin
from collections import deque

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())


dq = deque()

for _ in range(int(input())):
    s = input().rstrip().split()
    if s[0] == 'push_front':
        dq.appendleft(s[-1])
    elif s[0] == 'push_back':
        dq.append(s[-1])
    elif s[0] == 'pop_front':
        print(dq.popleft() if dq else -1)
    elif s[0] == 'pop_back':
        print(dq.pop() if dq else -1)
    elif s[0] == 'size':
        print(len(dq))
    elif s[0] == 'empty':
        print(0 if dq else 1)
    elif s[0] == 'front':
        print(dq[0] if dq else -1)
    elif s[0] == 'back':
        print(dq[-1] if dq else -1)
