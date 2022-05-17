class Solution:
    def maxEvents(self, e: List[List[int]]) -> int:
        a = [[] for i in range(100001)]
        q = []
        for x, y in e:
            a[x].append(y)
        z = 0
        for i in range(100001):
            for j in a[i]:
                heapq.heappush(q, j)
            while q and q[0] < i:
                heapq.heappop(q)
            if q:
                z += 1
                heapq.heappop(q)
        return z