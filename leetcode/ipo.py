import heapq
class Solution:
    def findMaximizedCapital(self, k: int, w: int, p: List[int], c: List[int]) -> int:
        a = sorted(zip(c, p))
        i = 0
        q = []
        for j in range(k):
            while i < len(a) and a[i][0] <= w:
                heapq.heappush(q, -a[i][1])
                i += 1
            if len(q) == 0:
                break
            w -= heapq.heappop(q)
        return w