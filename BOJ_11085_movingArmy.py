import sys
input = sys.stdin.readline

def find(u):
    if parents[u] == u: return u;
    parents[u] = find(parents[u])
    return parents[u]

def union(u, v):
    u = find(u); v = find(v);
    if u == v: return;
    parents[v] = u; return;


p, w = map(int, input().rstrip().split())
c, v = map(int, input().rstrip().split())
parents = [i for i in range(p)]
info = []
local_minimum = float('inf')

for _ in range(w):
    info.append(list(map(int, input().rstrip().split())))
info.sort(key=lambda x: -x[2])
for i in range(w):
    if find(parents[c]) == find(parents[v]): break;
    union(info[i][0], info[i][1])
    if local_minimum > info[i][2]: local_minimum = info[i][2];

print(local_minimum)