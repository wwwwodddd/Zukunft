# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        z = None
        def dfs(x):
            nonlocal z
            if x is None:
                return 0
            s = dfs(x.left) + dfs(x.right) + (x == q) + (x == p)
            if s == 2 and z is None:
                z = x
            return s
        dfs(root)
        return z