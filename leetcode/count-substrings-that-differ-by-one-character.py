class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        z = 0
        for i in range(len(s)):
            for j in range(len(t)):
                k = c = 0
                while i + k < len(s) and j + k < len(t):
                    if s[i + k] != t[j + k]:
                        c += 1
                    if c == 1:
                        z += 1
                    elif c > 1:
                        break
                    k += 1
        return z