# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root==None:
            return []
        if root.left==None and root.right==None and root.val==targetSum:
            return [[targetSum]]
        return [[root.val] + i for i in self.pathSum(root.left, targetSum-root.val) + self.pathSum(root.right, targetSum-root.val)]