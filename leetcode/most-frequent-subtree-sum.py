# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        c = Counter()
        def dfs(x):
            s = x.val
            if x.left:
                s += dfs(x.left)
            if x.right:
                s += dfs(x.right)
            c[s] += 1
            return s
        dfs(root)
        z = max(c.values())
        return [i for i in c if c[i]==z]