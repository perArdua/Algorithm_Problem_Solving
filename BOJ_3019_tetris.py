import sys
input = sys.stdin.readline



ans = 0
C, P = map(int, input().strip().split())
cols = [int(x) for x in input().strip().split()]

def one():
    global ans
    ans += C
    for i in range(C - 3):
        if cols[i] == cols[i + 1] == cols[i + 2] == cols[i + 3]:
            ans += 1
def two():
    global ans
    for i in range(C - 1):
        if cols[i] == cols[i + 1]:
            ans += 1
def three():
    global ans
    for i in range(C - 2):
        if cols[i] == cols[i + 1] and cols[i] + 1 == cols[i + 2]:
            ans += 1
    for i in range(C - 1):
        if cols[i] == cols[i + 1] + 1:
            ans += 1
def four():
    global ans
    for i in range(C - 2):
        if cols[i + 1] == cols[i + 2] and cols[i] == cols[i + 2] + 1:
            ans += 1
    for i in range(C - 1):
        if cols[i] + 1 == cols[i + 1]:
            ans += 1
def five():
    global ans
    for i in range(C - 2):
        if cols[i] == cols[i + 1] == cols[i + 2]:
            ans += 1
    for i in range(C - 1):
        if cols[i] == cols[i + 1] + 1:
            ans += 1
    for i in range(C - 1):
        if cols[i] + 1 == cols[i + 1]:
            ans += 1
    for i in range(C - 3 + 1):
        if cols[i] == cols[i + 1] + 1 == cols[i + 2]:
            ans += 1
def six():
    global ans
    for i in range(C - 2):
        if cols[i] == cols[i + 1] == cols[i + 2]:
            ans += 1
        if cols[i] + 1 == cols[i + 1] == cols[i + 2]:
            ans += 1
    for i in range(C - 1):
        if cols[i] == cols[i + 1]:
            ans += 1
        if cols[i] == cols[i + 1] + 2:
            ans += 1
def seven():
    global ans
    for i in range(C - 2):
        if cols[i] == cols[i + 1] == cols[i + 2]:
            ans += 1
        if cols[i] == cols[i + 1] == cols[i + 2] + 1:
            ans += 1
    for i in range(C - 1):
        if cols[i] == cols[i + 1]:
            ans += 1
        if cols[i] == cols[i + 1] - 2:
            ans += 1
            
if P == 1:
    one()
elif P == 2:
    two()
elif P == 3:
    three()
elif P == 4:
    four()
elif P == 5:
    five()
elif P == 6:
    six()
elif P == 7:
    seven()
print(ans)
