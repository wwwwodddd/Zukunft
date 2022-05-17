# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(postorder) == 0:
            return None
        x = TreeNode(postorder[-1])
        p = inorder.index(postorder[-1])
        x.left = self.buildTree(inorder[:p], postorder[:p])
        x.right = self.buildTree(inorder[p+1:], postorder[p:-1])
        return x