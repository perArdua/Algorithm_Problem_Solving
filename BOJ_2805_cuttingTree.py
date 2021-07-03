from sys import stdin

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

n, m = MIS()
tree = list(MIS())
lo, hi = 1, max(tree)

while lo <= hi:
    mid = (lo + hi) >> 1
    if sum([i - mid for i in tree if i - mid > 0]) >= m:
        lo = mid + 1
    else:
        hi = mid - 1

print(hi)
