from sys import stdin
from collections import Counter
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())


input()
arr = Counter(MIS())
n = input()
target = list(MIS())
print(*[arr[x] if x in arr else 0 for x in target])
