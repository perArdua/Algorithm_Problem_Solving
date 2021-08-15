import sys
input = sys.stdin.readline

n = int(input().rstrip())
res = 0 
for _ in range(n):
    in_string = input().rstrip()
    stack = []
    for c in in_string:
        if stack and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    if not stack:
        res += 1
print(res)