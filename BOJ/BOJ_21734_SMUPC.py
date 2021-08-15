import sys
input = sys.stdin.readline

tmp = input()

for c in tmp:
    print(c * sum(int(i) for i in str(ord(c))))
    