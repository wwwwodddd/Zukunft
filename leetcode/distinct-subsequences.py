class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        f = [0 for i in range(len(t)+1)]
        f[0] = 1
        for i in s:
            for j in range(len(t))[::-1]:
                if t[j] == i:
                    f[j + 1] += f[j]
        return f[len(t)]