import sys
input = sys.stdin.readline

def find(u):
    if u == parents[u]: return u;
    parents[u] = find(parents[u])
    return parents[u]

def union(u, v):
    u = find(u); v = find(v);
    if u == v: return;
    if u > v: u, v = v, u;
    parents[v] = u; return;

N, M = map(int, input().rstrip().split())
second_line = list(map(int, input().rstrip().split()))
parents = [i for i in range(N + 1)]
know_truth = [x for x in second_line[1:second_line[0] + 1]]
parties = [list(map(int, input().rstrip().split())) for _ in range(M)]

for element in know_truth:
    union(0, element)

for party in parties:
    for i in range(1, party[0]):
        union(find(party[i]), find(party[i + 1]))

res = 0

for party in parties:
    flag = True
    for p in party[1:]:
        if find(p) == 0: flag = False; break;
    if flag: res +=1 ;

print(res)