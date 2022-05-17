# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def shi(x, y):
            if x==None and y==None:
                return True
            if x==None or y==None:
                return False
            if x.val!=y.val:
                return False
            return shi(x.left,y.right) and shi(x.right,y.left)
        return shi(root, root)