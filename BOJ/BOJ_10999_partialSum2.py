import sys
input = sys.stdin.readline

class SegmentTree:
    def __init__(self, array):
        self.n = len(array)
        self.vector = [0] * 4 * self.n
        self.lazy = [0] * 4 * self.n
        self.init(array, 1, 0, self.n - 1)

    def init(self, array, node, left, right):
        if left == right:
            self.vector[node] = array[left]
            return self.vector[node]
        
        mid = (left + right) // 2
        self.vector[node] = self.init(array, node * 2, left, mid) + self.init(array, node * 2 + 1, mid + 1, right)
        return self.vector[node]

    def query(self, left, right, node, node_left, node_right):
        self.lazy_update(node, node_left, node_right)
        if right < node_left or node_right < left:
            return 0

        if left <= node_left and node_right <= right:
            return self.vector[node]
        
        mid = (node_left + node_right) // 2
        return self.query(left, right, node * 2, node_left, mid) + self.query(left, right, node * 2 + 1, mid + 1, node_right)

    def use_query(self, left, right):
        return self.query(left, right, 1, 0, self.n - 1)

    def lazy_update(self, node, node_left, node_right):
        if self.lazy[node] != 0:
            self.vector[node] += self.lazy[node] * (node_right - node_left + 1)
            if node_left != node_right:
                self.lazy[node * 2] += self.lazy[node]
                self.lazy[node * 2 + 1] += self.lazy[node]
            self.lazy[node] = 0
        return

    def update_range(self, node, node_left, node_right, left, right, delta):
        self.lazy_update(node, node_left, node_right)
        if node_right < left or right < node_left:
            return
        if left <= node_left and node_right <= right:
            self.vector[node] += delta * (node_right - node_left + 1)
            if node_left != node_right:
                self.lazy[node * 2] += delta
                self.lazy[node * 2 + 1] += delta
            return

        mid = (node_left + node_right) // 2
        self.update_range(node * 2, node_left, mid, left, right, delta)
        self.update_range(node * 2 + 1, mid + 1, node_right, left, right, delta)
        self.vector[node] = self.vector[node * 2] + self.vector[node * 2 + 1]

    def use_update_range(self, left, right, delta):
        self.update_range(1, 0, self.n - 1, left, right, delta)

n, m, k = [int(x) for x in input().rstrip().split()]
array = []

for _ in range(n):
    array.append(int(input().rstrip()))

tree = SegmentTree(array)

for i in range(m + k):
    tmp = [int(x) for x in input().rstrip().split()]
    if tmp[0] == 1:
        tree.use_update_range(tmp[1] - 1, tmp[2] - 1, tmp[-1])
    else:
        print(tree.use_query(tmp[1] - 1, tmp[2] - 1))
