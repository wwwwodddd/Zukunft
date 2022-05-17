# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        z = 0
        def dfs(x, v):
            nonlocal z
            if x == None:
                return
            if x.left == None and x.right == None:
                z += 10 * v + x.val
                return
            dfs(x.left, v * 10 + x.val)
            dfs(x.right, v * 10 + x.val)
        dfs(root, 0)
        return z