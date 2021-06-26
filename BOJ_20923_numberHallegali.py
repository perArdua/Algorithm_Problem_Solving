import sys
from collections import deque

input = sys.stdin.readline
MIS = lambda: map(int, input().rstrip().split())

n, m = MIS()
do, su = deque([]), deque([])
g_do, g_su = deque([]), deque([])
cnt = 0
for _ in range(n):
    a, b = MIS()
    do.append(a)
    su.append(b)

while True:
    g_do.append(do.pop())
    cnt += 1

    if not do:
        print("su")
        exit(0)
    if g_do[-1] == 5 or (g_su and g_su[-1] == 5):
        do.extendleft(g_su)
        do.extendleft(g_do)
        g_do, g_su = deque([]), deque([])

    elif g_su and (g_do[-1] + g_su[-1]) == 5:
        su.extendleft(g_do)
        su.extendleft(g_su)
        g_do, g_su = deque([]), deque([])

    if cnt == m:
        break

    g_su.append(su.pop())
    cnt += 1
    if not su:
        print("do")
        exit(0)

    if (g_do and g_do[-1] == 5) or g_su[-1] == 5:
        do.extendleft(g_su)
        do.extendleft(g_do)
        g_do, g_su = deque([]), deque([])

    elif g_do and (g_do[-1] + g_su[-1]) == 5:
        su.extendleft(g_do)
        su.extendleft(g_su)
        g_do, g_su = deque([]), deque([])

    if cnt == m:
        break

if len(do) == len(su):
    print("dosu")
elif len(do) > len(su):
    print("do")
else:
    print("su")
