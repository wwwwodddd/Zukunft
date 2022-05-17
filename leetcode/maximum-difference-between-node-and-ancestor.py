# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(x, mn, mx):
            nonlocal z
            if x == None:
                return
            mn = min(mn, x.val)
            mx = max(mx, x.val)
            z = max(z, mx - mn)
            dfs(x.left, mn, mx)
            dfs(x.right, mn, mx)
        dfs(root, root.val, root.val)
        return z