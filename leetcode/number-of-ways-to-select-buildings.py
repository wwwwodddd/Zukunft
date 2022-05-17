class Solution:
    def numberOfWays(self, s: str) -> int:
        def F(s, t):
            f = [0] * (len(t) + 1)
            f[0] = 1
            for i in s:
                for j in range(len(t))[::-1]:
                    if t[j] == i:
                        f[j + 1] += f[j]
            return f[-1]
        return F(s, '010') + F(s, '101')