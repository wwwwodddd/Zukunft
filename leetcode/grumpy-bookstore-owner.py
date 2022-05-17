class Solution:
    def maxSatisfied(self, a: List[int], b: List[int], m: int) -> int:
        z = s = t = 0
        for i in range(len(a)):
            t += (1 - b[i]) * a[i]
            s += b[i] * a[i]
            if i >= m:
                s -= b[i - m] * a[i - m]
            z = max(z, s)
        return z + t