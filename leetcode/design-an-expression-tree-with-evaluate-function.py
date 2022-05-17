import abc 
from abc import ABC, abstractmethod 
"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""

class Node(ABC):
    # define your fields here
    def __init__(self, op, para):
        self.op = op
        self.para = para

    def evaluate(self) -> int:
        if self.op.isdigit():
            return int(self.op)
        a = []
        for i in self.para:
            a.append(i.evaluate())
        if self.op == '+':
            return a[0] + a[1]
        if self.op == '-':
            return a[0] - a[1]
        if self.op == '*':
            return a[0] * a[1]
        if self.op == '/':
            return a[0] // a[1]


"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""

class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        s = []
        for i in postfix:
            if i.isdigit():
                s.append(Node(i, []))
            else:
                y = s.pop()
                x = s.pop()
                s.append(Node(i, [x, y]))
        return s[-1]
		
"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""