# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        z = 10**10
        def dfs(x):
            nonlocal z
            if x == None:
                return
            if x.val != root.val:
                z = min(z, x.val)
            dfs(x.left)
            dfs(x.right)
        dfs(root)
        if z == 10**10:
            z = -1
        return z