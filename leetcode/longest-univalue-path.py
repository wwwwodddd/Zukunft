# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(x):
            nonlocal z
            if x == None:
                return None,0
            lv, ld = dfs(x.left)
            rv, rd = dfs(x.right)
            d = 0
            md = 0
            if x.val == lv:
                d += ld
                md = max(md, ld)
            if x.val == rv:
                d += rd
                md = max(md, rd)
            z = max(z, d)
            return x.val, md + 1
        dfs(root)
        return z