from sys import stdin

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())

k, n = MIS()
arr = [int(input()) for _ in range(k)]
lo, hi = 1, sum(arr) // len(arr)

while lo <= hi:
    mid = (lo + hi) // 2
    cnt = sum(map(lambda element: element // mid, arr))
    
    if cnt < n:
        hi = mid - 1

    elif cnt >= n:
        lo = mid + 1

print(hi)