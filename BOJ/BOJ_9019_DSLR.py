from sys import stdin
from collections import deque
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

def D(arg):
    arg *= 2
    if arg >= mod:
        arg %= mod
    return arg

def S(arg):
    arg -= 1
    if arg < 0:
        arg = 9999
    return arg

def L(arg):
    return (arg % 1000) * 10 + (arg // 1000)

def R(arg):
    return (arg % 10) * 1000 + (arg // 10)

func = {'D' : D, 'S' : S, 'L' : L, 'R' : R}
mod = 10000
for _ in range(int(input())):
    visited = [False] * 10000
    a, b = MIS()
    q = deque()
    q.append((a, ""))
    visited[a] = True
    while q:
        node = q.popleft()
        if node[0] == b:
            print(node[1])
            break
        for key in func.keys():
            tmp = func[key](node[0])
            if not visited[tmp]:
                visited[tmp] = True
                q.append((tmp, node[1] + key))

