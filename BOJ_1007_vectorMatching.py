import sys, itertools
from math import sqrt, inf
input = sys.stdin.readline

test_case = input().strip()
for _ in range(int(test_case)):
    list_size = int(input().strip())
    ans = inf
    all_x, all_y = [], []
    for _ in range(list_size):
        x, y = map(int, input().split())
        all_x.append(x)
        all_y.append(y)
    sum_x, sum_y = sum(all_x), sum(all_y)

    combinations_x = list(itertools.combinations(all_x, list_size // 2))
    combinations_y = list(itertools.combinations(all_y, list_size // 2))

    for i in range(len(combinations_x)):
        plus_x = sum(combinations_x[i])
        minus_x = sum_x - plus_x
        plus_y = sum(combinations_y[i])
        minus_y = sum_y - plus_y
        res = sqrt((plus_x - minus_x) ** 2 + (plus_y - minus_y) ** 2)
        ans = res if res < ans else ans
    print("%.6lf" % ans)

    2304 1007 3019 3986