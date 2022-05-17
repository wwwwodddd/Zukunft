# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(x):
            nonlocal z
            v = x.val
            if x.left and v != dfs(x.left):
                v = 1e9
            if x.right and v != dfs(x.right):
                v = 1e9
            if v != 1e9:
                z += 1
            return v
        if root:
            dfs(root)
        return z
