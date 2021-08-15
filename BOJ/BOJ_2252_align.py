import sys
input = sys.stdin.readline

def dfs(here):
    check[here] = True
    for there in dic[here]:
        if check[there]: continue;
        dfs(there)
    ans.append(here)

def dfs_all():
    for node in range(1, N + 1):
        if check[node]: continue;
        dfs(node)

N, M = map(int, input().rstrip().split())
dic = {i : [] for i in range(N + 1)}
check = [False for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, input().rstrip().split())
    dic[u].append(v)

ans = []
dfs_all()

print(*ans[::-1])

