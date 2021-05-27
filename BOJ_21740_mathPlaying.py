import sys
from functools import cmp_to_key
input = sys.stdin.readline
MIS = lambda : map(int, input().rstrip().split())

input()
convert = {str(i) : str(i) for i in range(10)}
convert['6'] = '9'
convert['9'] = '6'

def cmp(x, y):
    left, right = x + y, y + x
    return 1 if left > right else 0 if left == right else -1

def cmp2(x, y):
    len_x, len_y = len(x), len(y)
    if len_x == len_y:
        a, b = int(x), int(y)
        return 1 if a > b else 0 if a == b else -1
    return 1 if len_x > len_y else 0 if len_x == len_y else -1

def reverse(x):
    ret = ''
    for i in x[::-1]:
        ret += convert[i]
    return ret

arr = [reverse(x) for x in input().rstrip().split()]
arr.sort(key=cmp_to_key(cmp2))
arr += [arr[-1]]
arr.sort(key=cmp_to_key(cmp))
print(''.join(map(reverse, arr)))
print(arr)