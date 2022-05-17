class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        a = sorted((-efficiency[i], speed[i]) for i in range(n))
        q = []
        s = 0
        z = 0
        for x, y in a:
            heappush(q, y)
            s += y
            if len(q) > k:
                s -= heappop(q)
            z = max(z, s * -x)
        return z % 1000000007