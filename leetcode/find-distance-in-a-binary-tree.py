# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        z = 0
        def dfs(x):
            nonlocal z
            if x is None:
                return 0
            l = dfs(x.left)
            r = dfs(x.right)
            z += l + r
            return l ^ r ^ (x.val == q) ^ (x.val == p)
        dfs(root)
        return z