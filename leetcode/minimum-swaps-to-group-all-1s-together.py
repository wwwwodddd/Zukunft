class Solution:
    def minSwaps(self, a: List[int]) -> int:
        c = sum(a)
        z = s = sum(a[:c])
        for i in range(c, len(a)):
            s += a[i] - a[i - c]
            z = max(z, s)
        return c - z
        