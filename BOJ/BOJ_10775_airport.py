import sys
sys.setrecursionlimit(int(1e5) + 1)
input = sys.stdin.readline

def find(u: int) -> int:
    if parent[u] == u: return u;
    parent[u] = find(parent[u])
    return parent[u]


G = int(input().rstrip())
P = int(input().rstrip())
parent = [i for i in range(G + 1)]
res = 0
planes = [int(input().rstrip()) for _ in range(P)]
for plane in planes:
    p = find(plane)
    if parent[p] != 0:
        res += 1
        parent[p] -= 1
    else:
        print(res)
        break
print(res)