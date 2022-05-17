# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        z = True
        def dfs(x):
            nonlocal z
            if x == None:
                return 0
            l = dfs(x.left)
            r = dfs(x.right)
            if abs(l - r) > 1:
                z = False
            return max(l, r) + 1
        dfs(root)
        return z