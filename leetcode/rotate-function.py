class Solution:
    def maxRotateFunction(self, a: List[int]) -> int:
        z = -10**100
        n = len(a)
        s = sum(a)
        c = 0
        for i in range(n):
            c += i * a[i]
        for i in range(n):
            z = max(z, c)
            c += s
            c -= a[n - 1 - i] * n
        return z