# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
        h = t = ListNode()
        while a != None or b != None:
            if a == None or (b != None and b.val < a.val):
                t.next = b
                t = t.next
                b = b.next
            else:
                t.next = a
                t = t.next
                a = a.next
        return h.next
