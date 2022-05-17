class Solution:
    def minSwaps(self, a: List[int]) -> int:
        n = len(a)
        m = a.count(1)
        z = s = sum(a[:m])
        for i in range(m, 2 * n):
            s += a[i % n] - a[(i - m) % n]
            z = max(z, s)
        return m - z