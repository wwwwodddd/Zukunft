# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def hao(x):
            if x == None:
                return 0
            return hao(x.left) + 1
        if root == None:
            return 0
        l = hao(root.left)
        r = hao(root.right)
        if l == r:
            return 2 ** l + self.countNodes(root.right)
        else:
            return 2 ** r + self.countNodes(root.left)