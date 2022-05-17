class Solution:
    def minimumLines(self, a: List[List[int]]) -> int:
        def xm(a, b, c):
            return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
        n = len(a)
        f = [n for i in range(1 << n)]
        for i in range(n):
            for j in range(i + 1, n):
                b = 1 << i | 1 << j
                for k in range(j + 1, n):
                    if xm(a[i], a[j], a[k]) == 0:
                        b |= 1 << k
                f[b] = 1
        f[0] = 0
        for i in range(1 << n):
            for j in range(1 << n):
                f[i | j] = min(f[i | j], f[i] + f[j])
        return f[-1]