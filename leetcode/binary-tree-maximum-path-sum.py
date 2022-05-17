# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        z = -9**9
        def dfs(x):
            nonlocal z
            if x == None:
                return 0
            lv = dfs(x.left)
            rv = dfs(x.right)
            d = x.val
            md = 0
            if lv > 0:
                d += lv
                md = max(md, lv)
            if rv > 0:
                d += rv
                md = max(md, rv)
            z = max(z, d)
            return md + x.val
        dfs(root)
        return z