class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        def suan(s, m, p, a):
            while a[0] == 0:
                a.pop(0)
            z = 0
            for i in a:
                if s != i:
                    z += m
                    s = i
                z += p
            return z
        z = 9**9
        if targetSeconds // 60 < 100:
            mn = targetSeconds // 60
            sc = targetSeconds % 60
            a = [mn // 10, mn % 10, sc // 10, sc % 10]
            z = suan(startAt, moveCost, pushCost, a)
        if targetSeconds % 60 < 40:
            mn = targetSeconds // 60 - 1
            sc = targetSeconds % 60 + 60
            a = [mn // 10, mn % 10, sc // 10, sc % 10]
            z = min(z, suan(startAt, moveCost, pushCost, a))
        return z    