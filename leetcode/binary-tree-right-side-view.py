# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        a = [root]
        z = []
        while True:
            a = [i for i in a if i]
            if a:
                z.append(a[-1].val)
            else:
                break
            a = [j for i in a for j in[i.left,i.right]]
        return z
        