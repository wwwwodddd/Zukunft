class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        c = Counter(i for i in s)
        return len(set(c.values())) == 1