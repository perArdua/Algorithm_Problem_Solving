import sys
input = sys.stdin.readline

src = input().rstrip()
flag = False
if src == 'P':
    print('PPAP')
    sys.exit()
elif len(src) < 4:
    print('NP')
    sys.exit()
else:
    res = []
    fixed = [x for x in 'PPAP']

    for c in src:
        res.append(c)
        if len(res) >= 4:
            if res[-4:] == fixed:
                for _ in range(4):
                    res.pop()
                res.append('P')

if len(res) == 1 and res[0] == 'P':
    print('PPAP')
else:
    print('NP')