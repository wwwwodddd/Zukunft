# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        def xun(r, f, d, x):
            if r == None:
                return None
            if r.val == x:
                return f, d
            return xun(r.left, r, d + 1, x) or xun(r.right, r, d + 1, x)
        fx, dx = xun(root, None, 0, x)
        fy, dy = xun(root, None, 0, y)
        return dx == dy and fx != fy