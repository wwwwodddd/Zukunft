# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums)==0:
            return None
        mx=max(nums)
        i=nums.index(mx)
        return TreeNode(mx,self.constructMaximumBinaryTree(nums[:i]),self.constructMaximumBinaryTree(nums[i+1:]))