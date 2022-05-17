class Solution:
    def maxDiff(self, n: int) -> int:
        n = str(n)
        mx = mn = n
        for i in n:
            mx = max(mx, n.replace(i, '9'))
            if i == n[0]:
                mn = min(mn, n.replace(i, '1'))
            else:
                mn = min(mn, n.replace(i, '0'))
        return int(mx) - int(mn)