class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        c = [0 for i in range(10001)]
        for i in nums:
            c[i] += i
        f = [0 for i in range(10001)]
        g = [0 for i in range(10001)]
        for i in range(1, 10001):
            f[i] = g[i-1] + c[i]
            g[i] = max(f[i-1],g[i-1])
        return max(f[10000],g[10000])