class Solution:
    def maxScore(self, s: str) -> int:
        t = s.count('1')
        z = 0
        for i in s[:-1]:
            if i == '0':
                t += 1
            else:
                t -= 1
            z = max(z, t)
        return z
            