# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, h: Optional[ListNode]) -> Optional[ListNode]:
        t = r = ListNode()
        s = 0
        while h:
            if h.val == 0:
                r.next = ListNode(s)
                r = r.next
                s = 0
            else:
                s += h.val
            h = h.next
        return t.next.next