from sys import stdin
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

n, m = MIS()
arr = list(MIS())

range_sum = [0] * len(arr)
range_sum[0] = arr[0]
for i in range(1, n):
    range_sum[i] = range_sum[i - 1] + arr[i]

for _ in range(m):
    u, v = MIS()
    u -= 1
    v -= 1
    print(range_sum[v] - range_sum[u - 1] if u - 1 >= 0 else range_sum[v])
