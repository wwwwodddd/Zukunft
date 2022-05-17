class Solution:
    def minSessions(self, a: List[int], k: int) -> int:
        n = len(a)
        f = [(n, k) for i in range(2 ** n)]
        f[0] = (0, k)
        for i in range(2 ** n):
            for j in range(n):
                if ~i >> j & 1:
                    if f[i][1] + a[j] <= k:
                        f[i | 1 << j] = min(f[i | 1 << j], (f[i][0], f[i][1] + a[j]))
                    else:
                        f[i | 1 << j] = min(f[i | 1 << j], (f[i][0] + 1, a[j]))
        return f[2 ** n - 1][0]