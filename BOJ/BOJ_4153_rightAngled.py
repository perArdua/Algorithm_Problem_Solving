from sys import stdin

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

arr = list(MIS())

while sum(arr) != 0:
    arr.sort()
    if arr[-1] ** 2 == arr[0] ** 2 + arr[1] ** 2:
        print('right')
    else:
        print('wrong')
    arr = list(MIS())