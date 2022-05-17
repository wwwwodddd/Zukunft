class Solution:
    def minmaxGasDist(self, a: List[int], k: int) -> float:
        L = 0
        R = 1e8
        for i in range(50):
            M = (L + R) / 2
            c = 0
            for j in range(1, len(a)):
                c += (a[j] - a[j - 1]) // M
            if c <= k:
                R = M
            else:
                L = M
        return R