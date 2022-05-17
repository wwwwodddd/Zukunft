# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        z = []
        def dfs(x, l, r, g):
            if x is None:
                return
            v = 0
            if v == 0 and l:
                z.append(x.val)
                v = 1
            dfs(x.left, l, r and x.right == None and not g, 0)
            if v == 0 and x.left is None and x.right is None:
                z.append(x.val)
                v = 1
            dfs(x.right, l and x.left is None and not g, r, 0)
            if v == 0 and r:
                z.append(x.val)
                v = 1
        dfs(root, 1, 1, 1)
        return z