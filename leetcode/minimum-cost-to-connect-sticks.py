class Solution:
    def connectSticks(self, a: List[int]) -> int:
        q = []
        for i in a:
            heapq.heappush(q, i)
        z = 0
        for i in range(len(a) - 1):
            x = heapq.heappop(q)
            y = heapq.heappop(q)
            z += x + y
            heapq.heappush(q, x + y)
        return z
