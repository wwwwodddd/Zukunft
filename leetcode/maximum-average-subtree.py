# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        v = 0
        def dfs(x):
            nonlocal v
            if x is None:
                return 0, 0
            ls, lc = dfs(x.left)
            rs, rc = dfs(x.right)
            s = ls + x.val + rs
            c = lc + 1 + rc
            v = max(v, s / c)
            return s, c
        dfs(root)
        return v