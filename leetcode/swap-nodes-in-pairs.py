# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, h: Optional[ListNode]) -> Optional[ListNode]:
        d = ListNode(0, h)
        i = d
        while i.next and i.next.next:
            a = i.next
            b = a.next
            c = b.next
            i.next = b
            b.next = a
            a.next = c
            i = a
        return d.next