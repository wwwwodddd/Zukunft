# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        z = None
        def dfs(root):
            nonlocal z
            if root is None:
                return
            if root.val > p.val:
                if z == None or z.val > root.val:
                    z = root
                dfs(root.left)
            else:
                dfs(root.right)
        dfs(root)
        return z