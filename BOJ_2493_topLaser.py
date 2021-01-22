import sys
input = sys.stdin.readline

n = int(input())
arr = [int(x) for x in input().rstrip().split()]
stack = []
ans = []

for i in range(len(arr)):
    while stack:
        if stack[-1][1] < arr[i]: stack.pop();
        else: ans.append((stack[-1][0])); break;
    if not stack: ans.append(0);
    stack.append((i + 1, arr[i]))

print(*ans)