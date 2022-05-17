class Solution:
    def maxProfit(self, k: int, a: List[int]) -> int:
        f = [0 for i in range(k + 1)]
        g = [-9**9 for i in range(k)]
        for i in a:
            for j in range(k):
                f[j+1] = max(f[j+1], g[j] + i)
                g[j] = max(g[j], f[j] - i)
        return f[k]