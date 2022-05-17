# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, h: ListNode, m: int, n: int) -> ListNode:
        t = ListNode(0, h)
        while True:
            for i in range(m):
                if t.next is None:
                    break
                t = t.next
            for i in range(n):
                if t.next is None:
                    break
                t.next = t.next.next
            if t.next is None:
                break
        return h