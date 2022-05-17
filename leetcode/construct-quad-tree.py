"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, a: List[List[int]]) -> 'Node':
        n = len(a)
        def zuo(l, r, u, d):
            c = 0
            for i in range(l, r):
                for j in range(u, d):
                    c += a[i][j]
            if c == 0:
                return Node(False, True, None, None, None, None)
            if c == (r - l) * (d - u):
                return Node(True, True, None, None, None, None)
            z = Node(False, False, None, None, None, None)
            z.topLeft = zuo(l, (l + r) // 2, u, (u + d) // 2)
            z.bottomLeft = zuo((l + r) // 2, r, u, (u + d) // 2)
            z.topRight = zuo(l, (l + r) // 2, (u + d) // 2, d)
            z.bottomRight = zuo((l + r) // 2, r, (u + d) // 2, d)
            return z
        return zuo(0, n, 0, n)