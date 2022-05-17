# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        z = []
        def dfs(x):
            if x is None:
                return True
            if x.left is None and x.right is not None:
                z.append(x.right.val)
            if x.left is not None and x.right is None:
                z.append(x.left.val)
            dfs(x.left)
            dfs(x.right)
        dfs(root)
        return z