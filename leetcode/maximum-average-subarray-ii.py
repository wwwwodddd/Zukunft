class Solution:
    def findMaxAverage(self, a: List[int], k: int) -> float:
        L = -1e4
        R = 1e4
        n = len(a)
        for i in range(50):
            M = (L + R) / 2
            s = [0 for i in range(n + 1)]
            for i in range(n):
                s[i + 1] = s[i] + a[i] - M
            z = -1e9
            p = 0
            for i in range(k, n + 1):
                p = min(p, s[i - k])
                z = max(z, s[i] - p)
            if z < 0:
                R = M
            else:
                L = M
        return L