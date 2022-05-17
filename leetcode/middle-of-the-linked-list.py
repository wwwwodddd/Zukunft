# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        h1 = h2 = head
        while True:
            if h2.next == None:
                return h1
            h2 = h2.next
            h1 = h1.next
            if h2.next == None:
                return h1
            h2 = h2.next
