from sys import stdin
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())


n = int(input())
a = list(input())
len_a = len(a)

for i in range(n - 1):
    b = list(input())
    for j in range(len_a):
        if a[j] != b[j]:
            a[j] = '?'
print("".join(a[:-1]))