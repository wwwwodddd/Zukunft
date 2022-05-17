# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def plusOne(self, h: ListNode) -> ListNode:
        t = ListNode(0, h)
        def add(x):
            if x is None:
                return 1
            x.val += add(x.next)
            if x.val == 10:
                x.val = 0
                return 1
            return 0
        t = add(h)
        if t:
            h = ListNode(1, h)
        return h