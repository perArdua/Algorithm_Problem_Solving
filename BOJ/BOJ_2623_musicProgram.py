import sys
input = sys.stdin.readline

def dfs(node):
    check[node] = True
    for next in graph[node]:
        if not check[next]: dfs(next)
    ans.append(node)

def dfs_all():
    for i in range(1, n + 1):
        if check[i]: continue;
        dfs(i)
    ret = ans[::-1]

    for i in range(len(ret)):
        for j in range(i + 1, len(ret)):
            if ret[i] in graph[ret[j]]:
                ret = []
                return ret
    return ret

n, m = map(int, input().rstrip().split())
graph = {i : [] for i in range(1, n + 1)}
check = [False for _ in range(n + 1)]
ans = []

for _ in range(m):
    line = list(map(int, input().rstrip().split()))
    for i in range(1, line[0]):
        graph[line[i]].append(line[i + 1])

res = dfs_all()
if res: print(*res);
else: print(0);