from sys import stdin

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

n, h = MIS()

arr = [0] * h

for i in range(n):
    if i & 1:
        arr[h - int(input().rstrip())] += 1
    else:
        arr[0] += 1
        arr[int(input().rstrip())] -= 1

for i in range(1, h):
    arr[i] += arr[i - 1]

res = min(arr)
cnt = arr.count(res)

print(res, cnt)
