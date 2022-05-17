# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, h: Optional[ListNode]) -> Optional[ListNode]:
        x = None
        while h:
            h.next, x, h = x, h, h.next
        return x