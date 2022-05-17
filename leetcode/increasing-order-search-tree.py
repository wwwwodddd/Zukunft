# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    curr = head = TreeNode(0, None, None)
    def increasingBST(self, root: TreeNode) -> TreeNode:
        if root == None:
            return False
        self.increasingBST(root.left)
        self.curr.right = TreeNode(root.val, None, None)
        self.curr = self.curr.right
        self.increasingBST(root.right)
        return self.head.right