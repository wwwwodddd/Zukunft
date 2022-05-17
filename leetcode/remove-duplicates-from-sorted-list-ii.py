# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        i = h = ListNode(0, head)
        while i and i.next:
            d = False
            while i.next and i.next.next and i.next.val == i.next.next.val:
                i.next.next = i.next.next.next
                d = True
            if d:
                i.next = i.next.next
            else:
                i = i.next
        return h.next