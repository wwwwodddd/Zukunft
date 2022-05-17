# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        f = [[] for i in range(n+1)]
        f[0].append(None)
        f[1].append(TreeNode())
        for i in range(2,n+1):
            for j in range(2,i):
                for l in f[j-1]:
                    for r in f[i-j]:
                        f[i].append(TreeNode(0,l,r))
        return f[n]