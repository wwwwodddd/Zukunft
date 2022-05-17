class Solution:
    def minAbsoluteSumDiff(self, a: List[int], b: List[int]) -> int:
        s = 0
        z = 0
        c = sorted(a)
        for i in range(len(b)):
            d = abs(a[i] - b[i])
            s += d
            j = bisect.bisect(c, b[i])
            if j > 0:
                z = max(z, d - b[i] + c[j - 1])
            if j < len(c):
                z = max(z, d - c[j] + b[i])
        return (s - z) % 1000000007