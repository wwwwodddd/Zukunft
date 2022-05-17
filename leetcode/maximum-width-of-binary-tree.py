# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, x: Optional[TreeNode]) -> int:
        mx = []
        mn = []
        def dfs(x, d, i):
            if x==None:
                return
            if d < len(mx):
                mx[d] = max(mx[d], i)
            else:
                mx.append(i)
            if d < len(mn):
                mn[d] = min(mn[d], i)
            else:
                mn.append(i)
            dfs(x.left, d + 1, i * 2)
            dfs(x.right, d + 1, i * 2 + 1)
        dfs(x, 0, 1)
        return max(x - y for x, y in zip(mx, mn)) + 1
