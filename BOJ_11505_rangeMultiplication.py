import sys
sys.setrecursionlimit(int(1e9))
input = sys.stdin.readline

class SegmentTree:
    MOD = int(1e9 + 7)
    def __init__(self, array):
        self.n = len(array)
        self.vector = [0] * 4 * self.n
        self.init(array, 1, 0, self.n - 1)

    def init(self, array, node, node_left, node_right):
        if node_left == node_right:
            self.vector[node] = array[node_left]
            return self.vector[node]
        mid = (node_left + node_right) // 2
        self.vector[node] = (self.init(array, node * 2, node_left, mid) * self.init(array, node * 2 + 1, mid + 1, node_right)) % self.MOD
        return self.vector[node]

    def query(self, node, node_left, node_right, left, right):
        if node_right < left or right < node_left:
            return 1
        if left <= node_left and node_right <= right:
            return self.vector[node]
        mid = (node_left + node_right) // 2
        return ((self.query(node * 2, node_left, mid, left, right) % self.MOD) * (self.query(node * 2 + 1, mid + 1, node_right, left, right) % self.MOD)) % self.MOD

    def use_query(self, left, right):
        return self.query(1, 0, self.n - 1, left, right)

    def update(self, node, node_left, node_right, idx, delta):
        if idx < node_left or node_right < idx:
            return
        if node_left == node_right:
            self.vector[node] = delta
            return
        mid = (node_left + node_right) // 2
        self.update(node * 2, node_left, mid, idx, delta)
        self.update(node * 2 + 1, mid + 1, node_right, idx, delta)
        self.vector[node] = (self.vector[node * 2] * self.vector[node * 2 + 1]) % self.MOD
    
    def use_update(self, idx, delta):
        self.update(1, 0, self.n - 1, idx, delta)

n, m, k = [int(x) for x in input().rstrip().split()]
array = []

for _ in range(n):
    array.append(int(input().rstrip()))

tree = SegmentTree(array)

for _ in range(m + k):
    tmp = [int(x) for x in input().rstrip().split()]
    if tmp[0] == 1:
        tree.use_update(tmp[1] - 1, tmp[-1])
    else:
        print(tree.use_query(tmp[1] - 1, tmp[-1] - 1))