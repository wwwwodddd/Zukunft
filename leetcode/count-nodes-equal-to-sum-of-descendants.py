# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(root):
            nonlocal z
            if root is None:
                return 0
            s = dfs(root.left) + dfs(root.right)
            if s == root.val:
                z += 1
            return s + root.val
        dfs(root)
        return z