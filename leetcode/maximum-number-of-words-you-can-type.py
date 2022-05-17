class Solution:
    def canBeTypedWords(self, s: str, b: str) -> int:
        b = set(b)
        return sum(len(set(w) & b) == 0 for w in s.split())