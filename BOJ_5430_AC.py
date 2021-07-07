from sys import stdin
from collections import deque
import re
input = stdin.readline
MIS = lambda: map(int, input().rstrip().split())
MIRS = lambda: map(int, stdin.readlines())

for _ in range(int(input())):
    command = input().rstrip()
    input()
    front = 1
    flag = False
    arr = deque([x for x in re.split('\D', input().rstrip()) if x != ''])
    for c in command:
        if c == 'R':
            front ^= 1
        else:
            if front:
                if arr:
                    arr.popleft()
                else:
                    print('error')
                    flag = True
                    break
            else:
                if arr:
                    arr.pop()
                else:
                    print('error')
                    flag = True
                    break
    if flag:
        continue
    else:
        if front:
            print('[' + ','.join(arr) + ']')
        else:
            arr = list(arr)
            print('[' + ','.join(arr[::-1]) + ']')