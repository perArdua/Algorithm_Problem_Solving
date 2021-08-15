import sys
input = sys.stdin.readline
MIS = lambda : map(int, input().rstrip().split())

n, k = MIS()
arr = list(map(int, input().rstrip().split()))
cnt = [0] * (int(1e5) + 1)
right = 0
ans = -1
for left in range(n):
    while right < n and cnt[arr[right]] < k:
        cnt[arr[right]] += 1
        right += 1
    ans = max(ans, right - left)
    cnt[arr[left]] -= 1
    left += 1

print(ans)