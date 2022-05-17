# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        if root == None:
            return []
        L = self.levelOrder(root.left);
        R = self.levelOrder(root.right);
        result = [[] for i in range(max(len(L), len(R)))]
        for i in range(len(L)):
            result[i] += L[i]
        for i in range(len(R)):
            result[i] += R[i]
        result = [[root.val]] + result
        return result
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        