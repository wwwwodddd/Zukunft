# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, x: Optional[TreeNode]):
        x.val = 0
        self.s = set()
        def dfs(x):
            self.s.add(x.val)
            if x.left:
                x.left.val = x.val * 2 + 1
                dfs(x.left)
            if x.right:
                x.right.val = x.val * 2 + 2
                dfs(x.right)
        dfs(x)

    def find(self, target: int) -> bool:
        return target in self.s


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)