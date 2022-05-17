# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, r1: Optional[TreeNode], r2: Optional[TreeNode]) -> bool:
        def dfs(x):
            if x==None:
                return []
            if x.left==None and x.right==None:
                return [x.val]
            return dfs(x.left) + dfs(x.right)
        return dfs(r1) == dfs(r2)