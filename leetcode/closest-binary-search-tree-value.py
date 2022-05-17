# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], t: float) -> int:
        z = 1e10
        zv = 0
        def dfs(root):
            nonlocal z, zv
            if root is None:
                return
            if z > abs(root.val - t):
                z = abs(root.val - t)
                zv = root.val
            if t < root.val:
                dfs(root.left)
            else:
                dfs(root.right)
        dfs(root)
        return zv