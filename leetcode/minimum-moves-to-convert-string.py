class Solution:
    def minimumMoves(self, s: str) -> int:
        i = 0
        z = 0
        while i < len(s):
            if s[i] == 'X':
                z += 1
                i += 3
            else:
                i += 1
        return z