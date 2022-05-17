# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, h: ListNode) -> ListNode:
        c = Counter()
        i = h
        while i:
            c[i.val] += 1
            i = i.next
        d = t = ListNode(0, h)
        while t.next:
            if c[t.next.val] > 1:
                t.next = t.next.next
            else:
                t = t.next
        return d.next