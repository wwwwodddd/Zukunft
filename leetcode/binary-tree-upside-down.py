# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.left is None:
            return root
        l = root.left
        t = self.upsideDownBinaryTree(root.left)
        l.left = root.right
        l.right = root
        root.left = root.right = None
        return t