# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(root):
            nonlocal z
            if root is None:
                return 0, 0
            ls, lc = dfs(root.left)
            rs, rc = dfs(root.right)
            s = ls + rs + root.val
            c = lc + rc + 1
            if s // c == root.val:
                z += 1
            return s, c
        dfs(root)
        return z