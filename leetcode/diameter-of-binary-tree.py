# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(x):
            nonlocal z
            l = r = 0
            if x.left:
                l = dfs(x.left) + 1
            if x.right:
                r = dfs(x.right) + 1
            z = max(z, l + r)
            return max(l, r)
        dfs(root)
        return z