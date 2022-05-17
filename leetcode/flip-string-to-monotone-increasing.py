class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        z = c = s.count('0')
        for i in s:
            if i == '1':
                c += 1
            else:
                c -= 1
            z = min(z, c)
        return z