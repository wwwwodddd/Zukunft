class Solution:
    def maxConsecutiveAnswers(self, s: str, k: int) -> int:
        z = 0
        j = c = 0
        for i in range(len(s)):
            if s[i] == 'T':
                c += 1
            while c > k:
                if s[j] == 'T':
                    c -= 1
                j += 1
            z = max(z, i - j + 1)
        j = c = 0
        for i in range(len(s)):
            if s[i] == 'F':
                c += 1
            while c > k:
                if s[j] == 'F':
                    c -= 1
                j += 1
            z = max(z, i - j + 1)
        return z