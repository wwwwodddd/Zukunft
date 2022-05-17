class Solution:
    def maximumProduct(self, a: List[int], k: int) -> int:
        q = []
        for i in a:
            heapq.heappush(q, i)
        for j in range(k):
            t = heapq.heappop(q)
            heapq.heappush(q, t + 1)
        z = 1
        for i in q:
            z = z * i % 1000000007
        return z