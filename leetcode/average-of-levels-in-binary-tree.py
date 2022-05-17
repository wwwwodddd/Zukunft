# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, x: Optional[TreeNode]) -> List[float]:
        s = []
        c = []
        def dfs(x, d):
            if x == None:
                return
            if d == len(s):
                s.append(0)
                c.append(0)
            s[d] += x.val
            c[d] += 1
            dfs(x.left, d + 1)
            dfs(x.right, d + 1)
        dfs(x, 0)
        return [x / y for x, y in zip(s, c)]