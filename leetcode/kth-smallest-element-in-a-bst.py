# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        z = 0
        def dfs(x):
            nonlocal k, z
            if x:
                dfs(x.left)
                k -= 1
                if k == 0:
                    z = x.val
                dfs(x.right)
        dfs(root)
        return z