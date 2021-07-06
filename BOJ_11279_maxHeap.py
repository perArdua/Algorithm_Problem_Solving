from sys import stdin
import heapq
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

arr = []

data = [-x for x in MIRS()]
for d in data[1:]:
    if not d:
        print(-heapq.heappop(arr) if arr else 0)
    else:
        heapq.heappush(arr, d)