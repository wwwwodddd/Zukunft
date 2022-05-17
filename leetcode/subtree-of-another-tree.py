# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def pei(s, t):
            if s==None or t==None:
                return s==t
            return s.val==t.val and pei(s.left, t.left) and pei(s.right, t.right)
        if root==None:
            return False
        return pei(root, subRoot) or self.isSubtree(root.left,subRoot) or self.isSubtree(root.right,subRoot)