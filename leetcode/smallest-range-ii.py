class Solution:
    def smallestRangeII(self, a: List[int], k: int) -> int:
        a.sort()
        z = a[-1] - a[0]
        for i in range(1, len(a)):
            z = min(z, max(a[-1], a[i-1] + 2 * k) - min(a[0] + 2 * k, a[i]))
        return z