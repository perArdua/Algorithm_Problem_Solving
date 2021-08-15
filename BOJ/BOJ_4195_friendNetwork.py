import sys
input = sys.stdin.readline


def find(u):
    if u == parents[u]: return u;
    parents[u] = find(parents[u])
    return parents[u]

def union(u, v):
    u = find(u); v = find(v);
    if u == v: return;
    parents[u] = v
    size[v] += size[u]
    return

TC = int(input().rstrip())
ans = []
for _ in range(TC):
    F = int(input().rstrip())
    dic = {}
    parents = [x for x in range(F * 2)]
    size = [1 for _ in range(F * 2)]
    order = 0
    res = 0
    for _ in range(F):
        a, b = input().rstrip().split()
        if dic.get(a, None) == None:
            dic[a] = order
            order += 1
        if dic.get(b, None) == None:
            dic[b] = order
            order += 1

        union(dic[a], dic[b])
        print(size[find(dic[b])])
