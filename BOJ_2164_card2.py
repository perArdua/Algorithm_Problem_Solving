from sys import stdin
from collections import deque
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

dq = deque([x for x in range(1, int(input()) + 1)])
while len(dq) != 1:
    dq.popleft()
    dq.append(dq.popleft())
print(dq[0])