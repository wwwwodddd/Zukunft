class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        z = 0
        for i in set(s):
            f = s.find(i)
            l = s.rfind(i)
            z += len(set(s[f + 1 : l]))
        return z