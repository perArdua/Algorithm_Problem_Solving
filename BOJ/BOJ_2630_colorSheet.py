from sys import stdin, setrecursionlimit
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())
setrecursionlimit(1<<11)

arr = [list(MIS()) for _ in range(int(input()))]
res = [0, 0]

def func(y, x, size):
    here = arr[y][x]
    for i in range(size):
        for j in range(size):
            if arr[y + i][x + j] != here:
                size //= 2
                func(y, x, size)
                func(y + size, x, size)
                func(y, x + size, size)
                func(y + size, x + size, size)
                return
    res[arr[y][x]] += 1

func(0, 0, len(arr))
print(*res,sep='\n')
