"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node==None:
            return None
        f = {}
        def dfs(x):
            if x.val in f:
                return
            f[x.val] = x
            for i in x.neighbors:
                dfs(i)
        dfs(node)
        g = {}
        for i in f:
            g[i] = Node(i)
        for i in f:
            g[i].neighbors = [g[j.val]for j in f[i].neighbors]
        return g[node.val]