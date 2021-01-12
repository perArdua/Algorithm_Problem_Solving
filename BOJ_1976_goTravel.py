import sys
input = sys.stdin.readline

class DS:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1] * (n)

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

n = int(input().rstrip())
m = int(input().rstrip())
ds = DS(n + 1)
results = []
for i in range(n):
    line = list(map(int, input().rstrip().split()))
    for j in range(len(line)):
        if line[j]:
            ds.union(i + 1, j + 1)

plan = [int(x) for x in input().rstrip().split()]
for i in range(len(plan) - 1):
    if ds.find(plan[i]) != ds.find(plan[i + 1]):
        print('NO')
        exit()
print('YES')


