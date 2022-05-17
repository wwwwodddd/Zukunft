class Solution:
    def removeVowels(self, s: str) -> str:
        for i in 'aeiou':
            s = s.replace(i, '')
        return s