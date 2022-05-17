class Solution:
    def maxProfit(self, a: List[int], m: int) -> int:
        a = sorted([0] + a, reverse=True)
        z = 0
        for i in range(1, len(a)):
            t = min(m // i, a[i - 1] - a[i])
            m -= i * t
            z += i * t * (a[i - 1] * 2 - t + 1) // 2
            if m < i:
                z += m * (a[i - 1] - t)
                break
        return z % 1000000007