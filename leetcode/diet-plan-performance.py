class Solution:
    def dietPlanPerformance(self, a: List[int], k: int, l: int, u: int) -> int:
        s = sum(a[:k])
        n = len(a)
        z = (s > u) - (s < l)
        for i in range(k, n):
            s += a[i] - a[i - k]
            z += (s > u) - (s < l)
        return z