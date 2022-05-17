# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode], d=0) -> int:
        if root==None:
            return 0
        if root.left==None and root.right==None:
            return root.val*d
        return self.sumOfLeftLeaves(root.left,1)+self.sumOfLeftLeaves(root.right,0)