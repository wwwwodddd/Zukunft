class Solution:
    def maxScore(self, a: List[int], k: int) -> int:
        z = s = sum(a[-k:])
        for i in range(k):
            s += a[i] - a[-k+i]
            z = max(z, s)
        return z