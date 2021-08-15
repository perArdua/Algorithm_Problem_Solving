import sys
input = sys.stdin.readline
src = input().rstrip()
boom = [x for x in input().rstrip()]
ans = []

for c in src:
    ans.append(c)
    if ans[-1] == boom[-1]:
        if ans[-len(boom):] == boom:
            for _ in range(len(boom)):
                ans.pop()
if not ans:
    print('FRULA')
else:
    print(''.join(ans))
