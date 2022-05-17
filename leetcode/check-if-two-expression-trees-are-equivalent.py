# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def dfs(x):
            if x is None:
                return []
            if x.val == '+':
                return dfs(x.left) + dfs(x.right)
            else:
                return [x.val]
        a = dfs(root1)
        b = dfs(root2)
        return sorted(a) == sorted(b)
