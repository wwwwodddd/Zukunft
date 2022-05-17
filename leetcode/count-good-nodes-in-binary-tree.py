# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        z = 0
        def dfs(x, y):
            nonlocal z
            y = max(y, x.val)
            if x.val >= y:
                z += 1
            if x.left:
                dfs(x.left, y)
            if x.right:
                dfs(x.right, y)
        dfs(root, -10000)
        return z