import sys
import heapq
input = sys.stdin.readline
MIS = lambda : map(int, input().rstrip().split())

left, right = [], []
ans = []
for _ in range(int(input())):
    num = int(input().rstrip())
    if len(left) == len(right):
        heapq.heappush(left, -num)
    else:
        heapq.heappush(right, num)

    if right and -left[0] > right[0]:
        tmp_left = heapq.heappop(left)
        tmp_right = heapq.heappop(right)
        heapq.heappush(right, -tmp_left)
        heapq.heappush(left, -tmp_right)
    
    ans.append(-left[0])

print(*ans,sep='\n')


