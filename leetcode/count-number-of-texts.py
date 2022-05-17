class Solution:
    def countTexts(self, s: str) -> int:
        p = 1000000007
        f = [1] + [0] * len(s)
        for i in range(len(s)):
            f[i + 1] = f[i]
            if i > 0 and s[i] == s[i - 1]:
                f[i + 1] = (f[i + 1] + f[i - 1]) % p
                if i > 1 and s[i] == s[i - 2]:
                    f[i + 1] = (f[i + 1] + f[i - 2]) % p
                    if i > 2 and s[i] == s[i - 3] and s[i] in ['7', '9']:
                        f[i + 1] = (f[i + 1] + f[i - 3]) % p
        return f[-1]