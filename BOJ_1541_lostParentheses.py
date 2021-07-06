import sys, re
exp = [sum(map(int, x.split('+'))) for x in re.split('-', sys.stdin.readline().rstrip())]
print(exp[0] - sum(exp[1:len(exp)]))
