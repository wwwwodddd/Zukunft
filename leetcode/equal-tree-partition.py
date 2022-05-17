# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEqualTree(self, root: TreeNode) -> bool:
        z = 0
        s = -1
        def dfs(x):
            nonlocal z
            if x is None:
                return 0
            c = dfs(x.left) + x.val + dfs(x.right)
            if 2 * c == s:
                z += 1
            return c
        s = dfs(root)
        dfs(root)
        return z >= 2 or s != 0 and z >= 1