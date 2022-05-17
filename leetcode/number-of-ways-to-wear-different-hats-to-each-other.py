class Solution:
    def numberWays(self, a: List[List[int]]) -> int:
        p = 1000000007
        n = len(a)
        f = [0 for i in range(1 << n)]
        f[0] = 1
        for i in range(1, 41):
            for j in range(1 << n)[::-1]:
                for k in range(n):
                    if j >> k & 1 and i in a[k]:
                        f[j] = (f[j] + f[j ^ 1 << k]) % p
        return f[2 ** n - 1]