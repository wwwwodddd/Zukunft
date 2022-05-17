# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        z = []
        def dfs(x, d):
            if x:
                if len(z) <= d:
                    z.append(x.val)
                else:
                    z[d] = max(z[d], x.val)
                dfs(x.left, d + 1)
                dfs(x.right, d + 1)
        dfs(root, 0)
        return z