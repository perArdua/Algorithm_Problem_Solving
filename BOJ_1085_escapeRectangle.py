from sys import stdin

input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())

x, y, w, h = MIS()
print(min(min(abs(x - w), abs(y - h)), min(x, y)))