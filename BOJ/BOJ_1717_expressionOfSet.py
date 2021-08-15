import sys
input = sys.stdin.readline

class DS:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.rank = [1] * (n + 1)

    def find(self, u):
        if u == self.parent[u]:
            return u
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return
        if self.rank[u] > self.rank[v]:
            u, v = v, u
        self.parent[u] = v
        if self.rank[u] == self.rank[v]:
            self.rank[v] += 1

n, m = map(int, input().rstrip().split())
ds = DS(n + 1)
results = []
for _ in range(m):
    tmp = [int(x) for x in input().rstrip().split()]
    if tmp[0] == 0:
        ds.union(tmp[1], tmp[2])
    else:
        results.append("YES" if ds.find(tmp[1]) == ds.find(tmp[2]) else "NO")
print('\n'.join(results))