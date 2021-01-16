import sys
input = sys.stdin.readline

def find(u):
    if parents[u] == u: return u;
    parents[u] = find(parents[u])
    return parents[u]

def union(u, v):
    u = find(u); v = find(v);
    if u == v: return;
    if fee[u - 1] > fee[v - 1]: u, v= v, u;
    parents[v] = u; return;


n, m, k = map(int, input().rstrip().split())
fee = [int(x) for x in input().rstrip().split()]
parents = [i for i in range(n + 1)]
paid = [False for _ in range(n + 1)]
relationships = []
money = 0
for _ in range(m):
    relationships.append(list(map(int, input().rstrip().split())))

for relation in relationships:
    union(relation[0], relation[1])

for i in range(1, n + 1):
    if not paid[find(parents[i])]: money += fee[find(parents[i]) - 1]; paid[find(parents[i])] = True;

print(money if money <= k else 'Oh no')