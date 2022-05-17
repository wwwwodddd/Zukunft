class Solution:
    def maxScoreSightseeingPair(self, a: List[int]) -> int:
        z = 0
        m = 0
        for i in range(len(a)):
            z = max(z, a[i] - i + m)
            m = max(m, a[i] + i)
        return z