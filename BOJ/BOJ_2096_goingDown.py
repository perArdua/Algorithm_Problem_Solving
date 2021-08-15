import sys
from copy import deepcopy
input = sys.stdin.readline

n = int(input())
max_arr = [[0 for _ in range(3)] for _ in range(2)]
min_arr = [[0 for _ in range(3)] for _ in range(2)]

for _ in range(n):
    tmp = list(map(int, input().split()))

    max_arr[1][0] = max(max_arr[0][0], max_arr[0][1]) + tmp[0]
    max_arr[1][1] = max(max_arr[0][0], max_arr[0][1], max_arr[0][2]) + tmp[1]
    max_arr[1][2] = max(max_arr[0][1], max_arr[0][2]) + tmp[2]

    min_arr[1][0] = min(min_arr[0][0], min_arr[0][1]) + tmp[0]
    min_arr[1][1] = min(min_arr[0][0], min_arr[0][1], min_arr[0][2]) + tmp[1]
    min_arr[1][2] = min(min_arr[0][1], min_arr[0][2]) + tmp[2]

    max_arr[0] = deepcopy(max_arr[1])
    min_arr[0] = deepcopy(min_arr[1])
print(max(max_arr[1]), min(min_arr[1]))