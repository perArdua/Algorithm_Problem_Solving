from operator import add, mul, sub, truediv
import sys
import re

input = sys.stdin.readline
n = int(input().rstrip())
arr = [int(x) if x.isdigit() else x for x in re.findall(r'[\D]|[\d]+', input().rstrip())]
div = lambda x, y: int(truediv(x, y))
operator = {'S' : sub, 'M' : mul, 'U' : div, 'P' : add}
res = arr[0]
ans = []

for sth in arr[1:]:
    if sth == 'C':
        ans.append(res)
    elif isinstance(sth, str):
        op = operator[sth]
    else:
        res = op(res, sth)

if ans:
    print(*ans)
else:
    print('NO OUTPUT')
