# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, h: Optional[ListNode]) -> Optional[ListNode]:
        i = h
        while i and i.next:
            while i.next and i.val == i.next.val:
                i.next = i.next.next
            i = i.next
        return h