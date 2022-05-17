# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, h: ListNode) -> int:
        z=0
        while h:
            z=z*2+h.val
            h=h.next
        return z