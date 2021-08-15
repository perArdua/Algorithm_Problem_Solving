import sys

row = 1
def cal(arg):
    stack = []
    ret = 0
    for c in arg:
        if c == '{':
            stack.append(c)
        else:
            if not stack:
                stack.append('{')
                ret += 1
            else:
                stack.pop()
    if stack:
        ret += int(len(stack) / 2)
    return ret


if __name__ == "__main__":
    while True:
        line = sys.stdin.readline().rstrip()
        if line[0] == '-':
            break
        else:
            print('{0}. {1}'.format(row, cal(line)))
            row += 1