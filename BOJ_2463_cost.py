import sys
sys.setrecursionlimit(1<<16)
input = sys.stdin.readline

def find(u):
    if parents[u] == u: return u;
    parents[u] = find(parents[u])
    return parents[u]

def union(u, v):
    u = find(u); v = find(v);
    if u == v: return;
    if rank[u] > rank[v]: u, v = v, u;
    parents[u] = v;
    if rank[u] == rank[v]: rank[v] += 1;
    size[v] += size[u]
    return;

MOD = int(1e9)
node, edge = map(int, input().split())
parents = [i for i in range(node + 1)]
rank = [1 for _ in range(node + 1)]
size = [1 for _ in range(node + 1)]
info = []
accumulated_cost = 0
for _ in range(edge):
    a, b, c = map(int, input().rstrip().split())
    if a > b: a, b = b, a;
    info.append((a, b, c))
    accumulated_cost += c

info.sort(key= lambda x: -x[2])

cost = 0

for i in info:
    u = find(i[0]); v = find(i[1]);
    if u != v:
        cost += accumulated_cost * size[u] * size[v]
        union(u, v)
    accumulated_cost -= i[2]
print(cost if cost < MOD else cost % MOD)