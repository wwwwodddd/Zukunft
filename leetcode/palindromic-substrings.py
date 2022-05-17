class Solution:
    def countSubstrings(self, s: str) -> int:
        z = 0
        for i in range(len(s)):
            x = y = i
            while x >= 0 and y < len(s) and s[x] == s[y]:
                z += 1
                x -= 1
                y += 1
            x = i
            y = i + 1
            while x >= 0 and y < len(s) and s[x] == s[y]:
                z += 1
                x -= 1
                y += 1
        return z