import sys
sys.setrecursionlimit(1<<16)
input = sys.stdin.readline

def find(u):
    if nodes[u] == u: return u;
    nodes[u] = find(nodes[u])
    return nodes[u]

def union(u, v):
    u = find(u); v = find(v);
    if u == v: return ;
    if rank[u] < rank[v]: u, v = v, u
    nodes[v] = u;
    if rank[u] == rank[v]: rank[u] += 1
    return ;

n, q = map(int, input().rstrip().split())
parents = [i for i in range(n + 1)]
nodes = [i for i in range(n + 1)]
rank = [1 for _ in range(n + 1)]
for i in range(2, n + 1):
    parents[i] = int(input().rstrip())

queries = []
ans = []
for _ in range(n - 1 + q):
    queries.append(list(map(int, input().rstrip().split())))

for tmp in queries[::-1]:
    if tmp[0] == 0:
        union(tmp[1], parents[tmp[1]])
    else:
        if find(tmp[1]) == find(tmp[2]): ans.append('YES');
        else: ans.append('NO')

print('\n'.join(ans[::-1]))