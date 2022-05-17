# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        fa = {}
        nd = {}
        for x, y, z in descriptions:
            if x not in nd:
                nd[x] = TreeNode(x)
            if y not in nd:
                nd[y] = TreeNode(y)
            fa[y] = x
            if z:
                nd[x].left = nd[y]
            else:
                nd[x].right = nd[y]
        for x in nd:
            if x not in fa:
                return nd[x]