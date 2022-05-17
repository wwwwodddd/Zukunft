# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        z = 0
        def dfs(r):
            nonlocal z
            if r == None:
                return []
            a = [i + r.val for i in [0] + dfs(r.left) + dfs(r.right)]
            z += a.count(targetSum)
            return a
        dfs(root)
        return z