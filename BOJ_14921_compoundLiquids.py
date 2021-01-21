import sys
input = sys.stdin.readline

n = int(input().rstrip())
arr = [int(x) for x in input().rstrip().split()]
res = float('inf')

lo = 0; hi = n - 1;

while lo < hi:
    candidate = arr[lo] + arr[hi]
    if abs(candidate) < abs(res):
        res = candidate
        if res == 0: print(res); exit();
    if candidate < 0: lo += 1
    elif candidate > 0: hi -= 1;
print(res)


