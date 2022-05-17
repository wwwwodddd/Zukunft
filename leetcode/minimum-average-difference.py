class Solution:
    def minimumAverageDifference(self, a: List[int]) -> int:
        n = len(a)
        s = 0
        t = sum(a)
        zd = 1e9
        zi = -1
        for i in range(n):
            s += a[i]
            t -= a[i]
            ss = s // (i + 1)
            tt = t // max((n - i - 1), 1)
            if zd > abs(ss - tt):
                zd = abs(ss - tt)
                zi = i
        return zi