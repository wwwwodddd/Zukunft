class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        z = c = 0
        for i in range(len(s)):
            if s[i] in 'aeiou':
                c += 1
            if i >= k and s[i - k] in 'aeiou':
                c -= 1
            z = max(z, c)
        return z