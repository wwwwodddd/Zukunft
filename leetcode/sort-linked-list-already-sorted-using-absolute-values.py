# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortLinkedList(self, h: Optional[ListNode]) -> Optional[ListNode]:
        f = l = ListNode(h.val)
        while h.next:
            h = h.next
            if h.val < 0:
                f = ListNode(h.val, f)
            else:
                l.next = ListNode(h.val, None)
                l = l.next
        return f