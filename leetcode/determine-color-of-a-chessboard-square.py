class Solution:
    def squareIsWhite(self, s: str) -> bool:
        return (ord(s[0]) + ord(s[1])) % 2 != 0