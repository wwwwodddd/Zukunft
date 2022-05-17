# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        s = 0
        if root == None:
            return s
        if root.val % 2 == 0:
            if root.left != None:
                if root.left.left != None:
                    s += root.left.left.val
                if root.left.right != None:
                    s += root.left.right.val
            if root.right != None:
                if root.right.left != None:
                    s += root.right.left.val
                if root.right.right != None:
                    s += root.right.right.val
        s += self.sumEvenGrandparent(root.left) + self.sumEvenGrandparent(root.right)
        return s