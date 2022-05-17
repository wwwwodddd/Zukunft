class Solution:
    def balancedStringSplit(self, s: str) -> int:
        z = 0
        c = 0
        for i in s:
            if i == 'R':
                c += 1
            else:
                c -= 1
            if c == 0:
                z += 1
        return z