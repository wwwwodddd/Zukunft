import queue
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        q = queue.PriorityQueue()
        for i, l in enumerate(lists):
            if l:
                q.put((l.val, i, l))
        h = t = ListNode()
        while q.qsize():
            v, i, x = q.get()
            h.next = ListNode()
            h = h.next
            h.val = v
            x = x.next
            if x:
                q.put((x.val, i, x))
        return t.next