# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: TreeNode) -> List[List[int]]:
        z = []
        def dfs(root):
            if root is None:
                return -1
            d = max(dfs(root.left), dfs(root.right)) + 1
            while len(z) <= d:
                z.append([])
            z[d].append(root.val)
            return d
        dfs(root)
        return z