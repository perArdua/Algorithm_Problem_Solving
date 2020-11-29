import sys

raw_data = sys.stdin.readline().rstrip()
res = 0
cnt = 0
len_raw_data = len(raw_data)
mul_stack = [1]

for i in range(len_raw_data):
    if raw_data[i] == '(':
        pass
    elif raw_data[i] == ')' and mul_stack:
        res += cnt * mul_stack.pop()
        cnt = 0
    else:
        if i + 1 != len_raw_data and raw_data[i + 1] == '(':
            k = mul_stack[-1]
            res += k * cnt
            cnt = 0
            if raw_data[i] == ')':
                mul_stack.append(k)
            else:
                mul_stack.append(k * int(raw_data[i]))
        else:
            cnt += 1
if cnt:
    res += cnt
print(res)
