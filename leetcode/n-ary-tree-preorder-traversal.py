"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root==None:
            return []
        z = [root.val]
        for c in root.children:
            z += self.preorder(c)
        return z