from sys import stdin

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

n = int(input())
print(n // 5 + n // 25 + n // 125)
