# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def dfs(x):
            if x==None:
                return 0, None
            ld, la = dfs(x.left)
            rd, ra = dfs(x.right)
            if ld > rd:
                return ld + 1, la
            elif ld < rd:
                return rd + 1, ra
            else:
                return ld + 1, x
        rd, ra = dfs(root)
        return ra