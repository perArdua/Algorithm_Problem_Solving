from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(1<<12)
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

arr = list(MIRS())

def dfs(here, lst):
    if len(lst) == 7:
        return True
    for there in range(here + 1, 9):
        lst.append(there)
        if dfs(there, lst):
            res = 0
            for dwarf in lst:
                res += arr[dwarf]
            if res == 100:
                print(*list(arr[x] for x in lst), sep='\n')
                exit(0)
        lst.pop()

    return False

dfs(-1, [])
