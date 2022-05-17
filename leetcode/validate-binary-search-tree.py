# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    a = -2**32
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        if not self.isValidBST(root.left):
            return False
        if root.val <= self.a:
            return False
        self.a = root.val
        if not self.isValidBST(root.right):
            return False
        return True
