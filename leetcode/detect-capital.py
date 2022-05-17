class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        return s.islower() or s.isupper() or s[0].isupper() and s[1:].islower()