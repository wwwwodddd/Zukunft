class Solution:
    def countVowels(self, s: str) -> int:
        z=0
        for i in range(len(s)):
            if s[i] in 'aeiou':
                z+=(i+1)*(len(s)-i)
        return z