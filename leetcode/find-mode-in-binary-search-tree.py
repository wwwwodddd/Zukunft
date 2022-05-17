# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        z = []
        c = 0
        v = f = 0
        def dfs(x):
            nonlocal z, c, v, f
            if x == None:
                return
            dfs(x.left)
            if x.val == v:
                f += 1
            else:
                v = x.val
                f = 1
            if c < f:
                c = f
                z = [v]
            elif c == f:
                z.append(v)
            dfs(x.right)

        dfs(root)
        return z
