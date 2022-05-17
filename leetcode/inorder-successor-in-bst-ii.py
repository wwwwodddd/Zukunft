"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Optional[Node]':
        if node.right:
            t = node.right
            while t.left:
                t = t.left
            return t
        while node.parent is not None:
            if node.parent.left == node:
                return node.parent
            else:
                node = node.parent
        return None