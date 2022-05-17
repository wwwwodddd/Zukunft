# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        if root == None:
            return []
        L = self.levelOrderBottom(root.left);
        R = self.levelOrderBottom(root.right);
        result = [[] for i in range(max(len(L), len(R)))]
        for i in range(1, len(L) + 1):
            result[-i] += L[-i]
        for i in range(1, len(R) + 1):
            result[-i] += R[-i]
        result += [[root.val]]
        return result
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        