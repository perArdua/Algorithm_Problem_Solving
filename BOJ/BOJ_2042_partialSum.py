import sys
input = sys.stdin.readline

class SegmentTree:
    def __init__(self, array):
        self.n = len(array)
        self.vector = [0] * 4 * self.n
        self.init(array, 1, 0, self.n - 1)
    
    def init(self, array, node, left, right):
        if left == right:
            self.vector[node] = array[left]
            return self.vector[node]
        
        mid = (left + right) // 2
        self.vector[node] = self.init(array, node * 2, left, mid) + self.init(array, node * 2 + 1, mid + 1, right)
        return self.vector[node]

    def query(self, left, right, node, node_left, node_right):
        if right < node_left or node_right < left:
            return 0

        if left <= node_left and node_right <= right:
            return self.vector[node]
        
        mid = (node_left + node_right) // 2
        return self.query(left, right, node * 2, node_left, mid) + self.query(left, right, node * 2 + 1, mid + 1, node_right)

    def use_query(self, left, right):
        return self.query(left, right, 1, 0, self.n - 1)

    def update(self, idx, diff, node, node_left, node_right):
        if idx < node_left or node_right < idx:
            return
        
        self.vector[node] += diff

        if node_left != node_right:
            mid = (node_left + node_right) // 2
            self.update(idx, diff, node * 2, node_left, mid)
            self.update(idx, diff, node * 2 + 1, mid + 1, node_right)
    
    def use_update(self, idx, diff):
        self.update(idx, diff, 1, 0, self.n - 1)

n, m, k = map(int, input().rstrip().split())
array = [0] * n
for i in range(n):
    array[i] = int(input().rstrip())

tree = SegmentTree(array)

for i in range(m + k):
    tmp = [int(x) for x in input().rstrip().split()]
    if tmp[0] == 1:
        tree.use_update(tmp[1] - 1, tmp[2] - array[tmp[1] - 1])
        array[tmp[1] - 1] = tmp[2]
    else:
        print(tree.use_query(tmp[1] - 1, tmp[2] - 1))