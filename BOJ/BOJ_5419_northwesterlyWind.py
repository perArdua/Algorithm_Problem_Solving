import sys, time
from math import log2, ceil
input = sys.stdin.readline

def manipulating_y(src):
    cnt = 0
    y[0] = cnt
    for i in range(1, len(src)):
        if src[i][1] != src[i - 1][1]:
            cnt += 1
        y[i] = cnt
    for i in range(len(src)):
        src[i][1] = y[i]
    src.sort(key=lambda x : (x[0], -x[1]))
    return src

def tree_sum(pos):
    pos += 1
    ret = 0
    while pos > 0:
        ret += nodes[pos]
        pos &= pos - 1
    return ret

def tree_add(pos, val):
    pos += 1
    while pos <= (1 << h) + 1:
        nodes[pos] += val
        pos += (pos & -pos)


if __name__ == '__main__':
    cases = int(input().rstrip())
    results = [0] * cases
    for case in range(cases):
        N = int(input().rstrip())
        h = int(ceil(log2(N))) + 1
        nodes = [0] * ((1 << h) + 1)
        y = [0] * 75001
        res = 0
        points = [list(map(int, input().rstrip().split())) for _ in range(N)]
        points.sort(key= lambda x: x[1])
        points = manipulating_y(points)
        for i in range(N):
            res += tree_sum(N) - tree_sum(points[i][1] - 1)
            tree_add(points[i][1], 1)
        results[case] = res
    ans = '\n'.join(map(str,results))
    print(ans)

