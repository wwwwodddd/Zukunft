class Solution:
    def goodDaysToRobBank(self, a: List[int], t: int) -> List[int]:
        n = len(a)
        f = [0 for i in range(n)]
        for i in range(1, n):
            if a[i] <= a[i - 1]:
                f[i] = f[i - 1] + 1
            else:
                f[i] = 0
        g = [0 for i in range(n)]
        for i in range(n - 1)[::-1]:
            if a[i] <= a[i + 1]:
                g[i] = g[i + 1] + 1
            else:
                g[i] = 0
        z = []
        for i in range(n):
            if f[i] >= t <= g[i]:
                z.append(i)
        return z