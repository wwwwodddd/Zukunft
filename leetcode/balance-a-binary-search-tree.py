# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def dfs(x):
            if x == None:
                return []
            return dfs(x.left) + [x.val] + dfs(x.right)
        a = dfs(root)
        def zao(a):
            if len(a) == 0:
                return None
            p = len(a) // 2
            x = TreeNode(a[p])
            x.left = zao(a[:p])
            x.right = zao(a[p+1:])
            return x
        return zao(a)