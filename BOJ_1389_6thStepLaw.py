from sys import stdin
from collections import deque
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

n, m = MIS()
g = {i : [] for i in range(1, n + 1)}

def bfs(start):
    check = [False for i in range(n + 1)]
    q = deque()
    q.append((start, 0))
    check[start] = True
    ret = 0
    while q:
        front = q.popleft()
        ret += front[-1]
        for there in g[front[0]]:
            if not check[there]:
                q.append((there, front[-1] + 1))
                check[there] = True
    return ret


for _ in range(m):
    a, b = MIS()
    g[a].append(b)
    g[b].append(a)

ans = (-1, float('inf'))
for here in range(1, n + 1):
    if (tmp := bfs(here)) < ans[-1]:
        ans = (here, tmp)
    
print(ans[0])

