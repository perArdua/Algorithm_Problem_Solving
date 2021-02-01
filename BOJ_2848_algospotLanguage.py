def make_dictionary():
    for i in range(len(words)):
        for j in range(i+1, len(words)):
            for k in range(min(len(words[i]), len(words[j]))):
                if words[i][k] != words[j][k]:
                    if words[j][k] in adj[words[i][k]]: break
                    adj[words[i][k]].append(words[j][k])
                    indegree[words[j][k]] += 1
                    break
                elif k == min(len(words[i]), len(words[j]))-1 and len(words[j]) < len(words[i]):
                    print('!')
                    exit(0)

def search():
    q = deque()
    for alpha in used_alpha:
        if not indegree[alpha]:
            q.append(alpha)
    if not q:
        print('!')
        exit()
    for _ in range(len(used_alpha)):
        if not q:
            return False
        if len(q) > 1:
            return False
        cur_node = q.popleft()
        ans.append(cur_node)
        for next_node in adj[cur_node]:
            indegree[next_node] -= 1
            if not indegree[next_node]:
                q.append(next_node)
    return True

from collections import defaultdict, deque
import sys
input = sys.stdin.readline
words = [input().rstrip() for _ in range(int(input()))]
used_alpha = set(''.join(words))
adj = defaultdict(list)
indegree = defaultdict(int)
make_dictionary()
ans = []
if search(): 
    print(''.join(ans))
else:
    print('?')
