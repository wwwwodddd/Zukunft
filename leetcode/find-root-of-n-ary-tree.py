"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def findRoot(self, t: List['Node']) -> 'Node':
        s = 0
        for i in t:
            s ^= i.val
            for j in i.children:
                s ^= j.val
        for i in t:
            if i.val == s:
                return i