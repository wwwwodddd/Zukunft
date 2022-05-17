# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        z = 0
        def dfs(root):
            nonlocal z
            t = 0
            if root.left:
                l = dfs(root.left)
                if root.left.val == root.val + 1:
                    t = max(t, l)
            if root.right:
                r = dfs(root.right)
                if root.right.val == root.val + 1:
                    t = max(t, r)
            t += 1
            z = max(z, t)
            return t
        dfs(root)
        return z