class Solution:
    def minDeletions(self, s: str) -> int:
        c = sorted(Counter(s).values(),reverse=True)
        z = 0
        for i in range(1, len(c)):
            t = max(min(c[i], c[i-1]-1), 0)
            z += c[i] - t
            c[i] = t
        return z