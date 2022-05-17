# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root == None:
            return TreeNode(val, None, None)
        curr = root
        while True:
            if val < curr.val:
                if curr.left == None:
                    curr.left = TreeNode(val, None, None)
                    break
                else:
                    curr = curr.left
            else:
                if curr.right == None:
                    curr.right  = TreeNode(val, None, None)
                    break
                else:
                    curr = curr.right
        return root