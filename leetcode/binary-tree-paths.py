# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root == None:
            return []
        if root.left == None and root.right == None:
            return ['%d' % root.val]
        return ['%d->%s' % (root.val, path) for path in self.binaryTreePaths(root.left) + self.binaryTreePaths(root.right)]