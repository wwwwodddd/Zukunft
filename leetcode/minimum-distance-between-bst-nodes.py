# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    z=1e9
    l=-1e9
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.z

    def dfs(self, r):
        if r==None:
            return
        self.dfs(r.left)
        self.z=min(self.z,r.val-self.l)
        self.l=r.val
        self.dfs(r.right)