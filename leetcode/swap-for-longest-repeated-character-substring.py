class Solution:
    def maxRepOpt1(self, s: str) -> int:
        z = 0
        for k in set(s):
            j = 0
            c = 0
            t = 0
            for i in range(len(s)):
                if s[i] != k:
                    c += 1
                while c > 1:
                    if s[j] != k:
                        c -= 1
                    j += 1
                t = max(t, i - j + 1)
            t = min(t, s.count(k))
            z = max(z, t)
        return z