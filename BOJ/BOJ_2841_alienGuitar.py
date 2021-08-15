import sys
input = sys.stdin.readline

res = 0
N, P = map(int, input().rstrip().split())
dic = {}
for _ in range(N):
    a, b = map(int, input().rstrip().split())
    if a in dic.keys():
        dic[a].append(b)
    else:
        dic[a] = [b]

for key in dic.keys():
    stack = []
    for i in range(len(dic[key])):
        if stack and stack[-1] == dic[key][i]:
            continue
        elif stack and stack[-1] > dic[key][i]:
            while stack and stack[-1] > dic[key][i]:
                stack.pop()
                res += 1
            if stack and stack[-1] == dic[key][i] :
                continue
            stack.append(dic[key][i])
            res += 1
        else:
            stack.append(dic[key][i])
            res += 1

print(res)
