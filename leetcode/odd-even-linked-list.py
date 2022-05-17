# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        o = p = ListNode()
        e = q = ListNode()
        c = 0
        while head:
            p.next = head
            p = q
            q = head
            head = head.next
            q.next = None
            c += 1
        if c & 1:
            p, q = q, p
        p.next = e.next
        return o.next