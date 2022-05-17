# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        s = []
        def dfs(x, d):
            if x == None:
                return
            if len(s) == d:
                s.append(0)
            s[d] += x.val
            dfs(x.left, d + 1)
            dfs(x.right, d + 1)
        dfs(root, 0)
        return s.index(max(s)) + 1