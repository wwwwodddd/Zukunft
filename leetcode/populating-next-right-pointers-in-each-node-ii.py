"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, r: 'Node') -> 'Node':
        h = r
        while h:
            c = h
            h = l = None
            while c:
                if c.left:
                    if l:
                        l.next = c.left
                    else:
                        h = c.left
                    l = c.left
                if c.right:
                    if l:
                        l.next = c.right
                    else:
                        h = c.right
                    l = c.right
                c = c.next
        return r