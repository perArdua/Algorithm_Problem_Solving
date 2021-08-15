import sys
sys.setrecursionlimit(1 << 14)
input = sys.stdin.readline

class SegmentTree:
    def __init__(self, array):
        self.array_length = len(array)
        self.range_min = [0] * self.array_length * 4
        self.init_tree(array, 0, self.array_length - 1, 1)

    def init_tree(self, array, left, right, node):
        if left == right:
            self.range_min[node] = array[left]
            return self.range_min[node]
        mid = (left + right) // 2
        self.range_min[node] = min(self.init_tree(array, left, mid, node * 2), self.init_tree(array, mid + 1, right, node * 2 + 1))
        return self.range_min[node]

    def query(self, left, right, node_left, node_right, node):
        if right < node_left or node_right < left:
            return 987654321
        if left <= node_left and node_right <= right:
            return self.range_min[node]
        mid = (node_left + node_right) // 2
        return min(self.query(left, right, node_left, mid, node * 2), 
                                    self.query(left, right, mid + 1, node_right, node * 2 + 1))
    
    def use_query(self, left, right):
        return self.query(left, right, 0, self.array_length - 1, 1)

n, m = map(int, input().rstrip().split())
array = [0] * n

for i in range(n):
    array[i] = int(input().rstrip())

tree = SegmentTree(array)
ans = []
for i in range(m):
    a, b = map(int, input().rstrip().split())
    print(tree.use_query(a - 1, b - 1))

