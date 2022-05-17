# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        if root:
            ld,lv=self.dfs(root.left)
            rd,rv=self.dfs(root.right)
            if ld == rd == 0:
                return (1,root.val)
            if ld == rd:
                return (ld+1,lv+rv)
            return max((ld+1,lv),(rd+1,rv))
        return (0,0)
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)[1]