class Solution:
    def maxRunTime(self, n: int, a: List[int]) -> int:
        a.sort()
        z = s = sum(a)
        for i in range(n):
            z = min(z, s // (n - i))
            s -= a[len(a) - 1 - i]
        return z