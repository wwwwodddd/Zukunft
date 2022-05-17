# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, a: List[int]) -> Optional[TreeNode]:
        if len(a) == 0:
            return None
        p = len(a) // 2
        x = TreeNode(a[p])
        x.left = self.sortedArrayToBST(a[:p])
        x.right = self.sortedArrayToBST(a[p+1:])
        return x