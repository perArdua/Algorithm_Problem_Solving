import sys

n = int(input())
x = [int(i) for i in sys.stdin.readline().rstrip().split()]
processed = list(sorted(set(x)))
processed = {processed[i] : i for i in range(len(processed))}
print(*[processed[i] for i in x])