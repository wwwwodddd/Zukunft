# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, h: Optional[ListNode]) -> bool:
        p = q = h
        while True:
            q = q.next
            if q is None:
                break
            q = q.next
            if q is None:
                break
            p = p.next
        q = p
        p = p.next
        q.next = None
        l = None
        while p:
            q = p.next
            p.next = l
            l = p
            p = q
        while l:
            if h.val != l.val:
                return False
            h = h.next
            l = l.next
        return True