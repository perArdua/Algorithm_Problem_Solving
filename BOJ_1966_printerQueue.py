from sys import stdin
from collections import deque
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

for _ in range(int(input())):
    n, m = MIS()
    dq = deque(zip(map(int, input().rstrip().split()), [x for x in range(n)]))
    target = dq[m]
    cnt = 1

    while True:
        max_value = max(dq, key=lambda x: x[0])
        if target == max_value:
            while dq[0][1] != m:
                dq.append(dq.popleft())
            break
        else:
            while dq[0] != max_value:
                dq.append(dq.popleft())
            dq.popleft()
            cnt += 1
    
    print(cnt)