class Solution:
    def maxSumAfterPartitioning(self, a: List[int], k: int) -> int:
        f = [0 for i in range(len(a) + 1)]
        for i in range(len(a)):
            mx = 0
            for j in range(i, min(len(a), i + k)):
                mx = max(mx, a[j])
                f[j + 1] = max(f[j + 1], f[i] + (j - i + 1) * mx)
        return f[len(a)]