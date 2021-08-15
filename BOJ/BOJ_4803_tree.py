import sys
input = sys.stdin.readline

def find(u):
    if u == nodes[u]: return u;
    nodes[u] = find(nodes[u])
    return nodes[u]

def union(u, v):
    u = find(u); v = find(v)
    if u == v or not root[u] or not root[v]:
        root[u], root[v] = False, False
    nodes[u] = v

while_var = 1
ans = []
while(True):
    n, m = map(int, input().rstrip().split())
    if not n and not m: break;
    res = 0
    nodes = [i for i in range(n + 1)]
    root = [True for i in range(n + 1)]

    for cur in range(m):
        u, v = map(int, input().rstrip().split())
        union(u, v)

    for _node in range(1, n + 1):
        tmp = find(_node)
        if root[tmp]:
            root[tmp] = False
            res += 1
    if not res: ans.append('Case {0}: No trees.'.format(while_var));
    elif res == 1: ans.append("Case {0}: There is one tree.".format(while_var));
    else: ans.append('Case {0}: A forest of {1} trees.'.format(while_var, res))
    while_var += 1
print('\n'.join(ans))