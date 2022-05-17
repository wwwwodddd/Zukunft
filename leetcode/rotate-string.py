class Solution:
    def rotateString(self, s: str, t: str) -> bool:
        for i in range(len(s)):
            if s[i:] + s[:i] == t:
                return True
        return False