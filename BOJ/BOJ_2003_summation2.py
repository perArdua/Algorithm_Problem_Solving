import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [int(x) for x in input().rstrip().split()]

lo = 0
hi = 0
res = 0
cur_sum = 0
while True:
    if cur_sum >= m:
        cur_sum -= arr[lo]
        lo += 1
    elif hi == n:
        break
    else:
        cur_sum += arr[hi]
        hi += 1
    if cur_sum == m:
        res += 1
print(res)