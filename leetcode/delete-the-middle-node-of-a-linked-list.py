# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, h: Optional[ListNode]) -> Optional[ListNode]:
        h1 = h2 = t = ListNode(0, h)
        while True:
            if h2.next==None or h2.next.next==None:
                h1.next=h1.next.next
                return t.next
            h1=h1.next
            h2=h2.next.next
