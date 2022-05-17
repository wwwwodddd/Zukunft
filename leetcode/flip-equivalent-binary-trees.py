# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, x: Optional[TreeNode], y: Optional[TreeNode]) -> bool:
        if x == None and y == None:
            return True
        if x == None or y == None:
            return False
        if x.val != y.val:
            return False
        if self.flipEquiv(x.left, y.left) and self.flipEquiv(x.right, y.right):
            return True
        if self.flipEquiv(x.left, y.right) and self.flipEquiv(x.right, y.left):
            return True
        return False
