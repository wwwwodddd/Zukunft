class Solution:
    def mincostToHireWorkers(self, q: List[int], w: List[int], k: int) -> float:
        a = sorted([(w[i] / q[i], q[i]) for i in range(len(q))])
        b = []
        s = 0
        z = 1e9
        for x, q in a:
            heapq.heappush(b, -q)
            s += q
            if len(b) > k:
                s += heapq.heappop(b)
            if len(b) == k:
                z = min(z, s * x)
        return z