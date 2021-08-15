from sys import stdin
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

input()
arr = [ord(x) - 96 for x in input().rstrip()]
s = 0

for i in range(len(arr)):
    s += arr[i] * pow(31, i)
    s %= 1234567891
print(s)