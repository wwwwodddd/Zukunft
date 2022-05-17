# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        def dfs(x):
            if x == None:
                return []
            return dfs(x.left) + [x.val] + dfs(x.right)
        a = dfs(root)
        i = 0
        j = len(a) - 1
        while i < j:
            if a[i] + a[j] < k:
                i += 1
            elif a[i] + a[j] > k:
                j -= 1
            else:
                return True
        return False