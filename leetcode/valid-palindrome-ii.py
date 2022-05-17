class Solution:
    def validPalindrome(self, s: str) -> bool:
        if len(s) < 2:
            return True
        if s[0] == s[-1]:
            return self.validPalindrome(s[1:-1])
        else:
            return s[1:] == s[1:][::-1] or s[:-1] == s[:-1][::-1]