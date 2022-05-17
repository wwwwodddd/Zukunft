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
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        a = [root]
        while a:
            a = [i for i in a if i]
            for i in range(1, len(a)):
                a[i-1].next = a[i]
            a = [j for i in a for j in[i.left,i.right]]
        return root