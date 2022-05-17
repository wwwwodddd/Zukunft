"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Codec:
    def node2list(self, root):
        if root is None:
            return []
        a = [root.val]
        for c in root.children:
            a.append(self.node2list(c))
        return a

    def list2node(self, arr):
        if arr == []:
            return None
        t = Node(arr[0], [])
        for a in arr[1:]:
            t.children.append(self.list2node(a))
        return t
    
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        return json.dumps(self.node2list(root))
	
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        return self.list2node(json.loads(data))
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))