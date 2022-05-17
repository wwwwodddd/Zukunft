class Solution:
    def maxAscendingSum(self, a: List[int]) -> int:
        n = len(a)
        s = 0
        z = 0
        for i in range(n):
            if i > 0 and a[i] > a[i-1]:
                s += a[i]
            else:
                s = a[i]
            z = max(z, s)
        return z
            