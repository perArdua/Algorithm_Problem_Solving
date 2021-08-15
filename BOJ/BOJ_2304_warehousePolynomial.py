import sys
input = sys.stdin.readline

n = int(input().rstrip())
LH = []
for _ in range(n):
    LH.append(list(map(int, input().rstrip().split())))
LH.sort(key=lambda x: x[0])
pivot_idx = LH.index(max(LH, key= lambda x: x[1]))
res = 0

maximal = -1
for i in range(pivot_idx):
    width = LH[i + 1][0] - LH[i][0]

    if maximal < LH[i][1]:
        maximal = LH[i][1]
    
    res += maximal * width
maximal = -1
for i in range(len(LH) - 1, pivot_idx, -1):
    width = LH[i][0] - LH[i - 1][0]

    if maximal < LH[i][1]:
        maximal = LH[i][1]
    
    res += maximal * width
res += LH[pivot_idx][1]
print(res)
