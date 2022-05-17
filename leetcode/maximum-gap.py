class Solution:
    def maximumGap(self, a: List[int]) -> int:
        n = len(a)
        s = min(a)
        d = max(a) - s
        if d == 0:
            return 0
        d = (d + n - 2) // (n - 1)
        mn = [10**10 for i in range(n)]
        mx = [-10**10 for i in range(n)]
        for i in a:
            mn[(i - s) // d] = min(mn[(i - s) // d], i)
            mx[(i - s) // d] = max(mx[(i - s) // d], i)
        z = 0
        x = mx[0]
        for i in range(1, n):
            if mn[i] != 10**10:
                z = max(z, mn[i] - x)
                x = mx[i]
        return z