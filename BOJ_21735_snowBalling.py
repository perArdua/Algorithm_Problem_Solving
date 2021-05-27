import sys
sys.setrecursionlimit(int(1e9))
input = sys.stdin.readline

n, m = map(int, input().split())
snow = list(map(int, input().rstrip().split()))

def dfs(cur_pos, total, time):
    if time == m or cur_pos == n - 1:
        return total
    ret, left, right = -float('inf'), -float('inf'), -float('inf')
    if cur_pos + 1 < n:
        left = dfs(cur_pos + 1, snow[cur_pos + 1] + total, time + 1)
    if cur_pos + 2 < n:
        right = dfs(cur_pos + 2, snow[cur_pos + 2] + (total // 2), time + 1)
    ret = max(left, right)
    return ret
print(dfs(-1, 1, 0))
