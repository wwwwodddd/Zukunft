# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, ha: ListNode, hb: ListNode) -> Optional[ListNode]:
        pa = ha
        la = 0
        while pa is not None:
            pa = pa.next
            la += 1
        pb = hb
        lb = 0
        while pb is not None:
            pb = pb.next
            lb += 1
        for i in range(la - lb):
            ha = ha.next
        for i in range(lb - la):
            hb = hb.next
        while ha is not hb:
            ha = ha.next
            hb = hb.next
        return ha