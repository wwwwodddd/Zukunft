class Solution:
    def binaryGap(self, n: int) -> int:
        a = []
        for i in range(32):
            if n >> i & 1:
                a.append(i)
        z = 0
        for i in range(1, len(a)):
            z = max(z, a[i] - a[i-1])
        return z