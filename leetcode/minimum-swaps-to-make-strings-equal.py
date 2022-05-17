class Solution:
    def minimumSwap(self, s: str, t: str) -> int:
        x = y = 0
        for i in range(len(s)):
            if s[i] != t[i]:
                if s[i] == 'x':
                    x += 1
                else:
                    y += 1
        if x % 2 != y % 2:
            return -1
        return (x + 1) // 2 + (y + 1) // 2