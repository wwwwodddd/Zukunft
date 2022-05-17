class Solution:
    def minimumDeletions(self, s: str) -> int:
        z = c = s.count('a')
        for i in s:
            if i == 'a':
                c -= 1
            else:
                c += 1
            z = min(z, c)
        return z