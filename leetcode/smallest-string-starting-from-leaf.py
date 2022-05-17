# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        z='~'
        def dfs(x,s):
            nonlocal z
            s=chr(97+x.val)+s
            if x.left==None and x.right==None:
                z=min(z,s)
            if x.left:
                dfs(x.left,s)
            if x.right:
                dfs(x.right,s)
        dfs(root, '')
        return z