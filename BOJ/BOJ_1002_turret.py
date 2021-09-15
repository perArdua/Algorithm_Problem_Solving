from sys import stdin
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

for _ in range(int(input().rstrip())):
    line = list(MIS())
    dist = ((line[0] - line[3]) ** 2 + (line[1] - line[4]) ** 2) ** 0.5
    if dist == 0 and line[2] == line[5]:
        print(-1)
    elif abs(line[2] - line[5]) == dist or line[2] + line[5] == dist:
        print(1)
    elif abs(line[2] - line[5]) < dist and dist < line[2] + line[5]:
        print(2)
    else:
        print(0)
