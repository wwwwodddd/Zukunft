class Solution:
    def deckRevealedIncreasing(self, a: List[int]) -> List[int]:
        a.sort(reverse=True)
        q = deque()
        for i in a:
            if len(q):
                q.appendleft(q.pop())
            q.appendleft(i)
        return q
            