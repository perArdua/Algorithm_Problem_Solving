import sys
input = sys.stdin.readline
MIS = lambda : map(int, input().rstrip().split())

n, k = MIS()
smallest, largest = 1, n
ans = [-1 for _ in range(n)]

for cur_pos in range(n):
    if k > 0 and (n - 1) - (cur_pos + 1) + 1 <= k:
        ans[cur_pos] = largest
        k -= (n - 1) - (cur_pos + 1) + 1
        largest -= 1
    else:
        ans[cur_pos] = smallest
        smallest += 1
print(*ans)