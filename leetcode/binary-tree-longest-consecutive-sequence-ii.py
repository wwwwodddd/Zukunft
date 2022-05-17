# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        z = 0
        def dfs(x):
            nonlocal z
            lf = lg = rf = rg = 0
            if x.left:
                lf, lg = dfs(x.left)
                if x.left.val != x.val + 1:
                    lf = 0
                if x.left.val != x.val - 1:
                    lg = 0
            if x.right:
                rf, rg = dfs(x.right)
                if x.right.val != x.val + 1:
                    rf = 0
                if x.right.val != x.val - 1:
                    rg = 0
            f = 1 + max(lf, rf)
            g = 1 + max(lg, rg)
            z = max(z, f + g - 1)
            return f, g
        dfs(root)
        return z