# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        x = TreeNode(preorder[0])
        p = inorder.index(preorder[0])
        x.left = self.buildTree(preorder[1:1+p], inorder[0:p])
        x.right = self.buildTree(preorder[1+p:], inorder[p+1:])
        return x