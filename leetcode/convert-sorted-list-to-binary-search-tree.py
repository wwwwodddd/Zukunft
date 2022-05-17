# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, h: Optional[ListNode]) -> Optional[TreeNode]:
        n = 0
        t = h
        while t:
            t = t.next
            n += 1
        def zao(l, r):
            nonlocal h
            if l > r:
                return None
            u = TreeNode()
            m = (l + r) // 2
            u.left = zao(l, m - 1)
            u.val = h.val
            h = h.next
            u.right = zao(m + 1, r)
            return u
        return zao(0, n - 1)
            