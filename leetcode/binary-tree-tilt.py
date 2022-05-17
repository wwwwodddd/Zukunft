# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        z=0
        def dfs(x):
            nonlocal z
            if x==None:
                return 0
            l=dfs(x.left)
            r=dfs(x.right)
            z+=abs(l-r)
            return l+r+x.val
        dfs(root)
        return z