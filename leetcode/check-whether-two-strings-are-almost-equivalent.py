class Solution:
    def checkAlmostEquivalent(self, s: str, t: str) -> bool:
        c = Counter()
        for i in s:
            c[i] += 1
        for i in t:
            c[i] -= 1
        return max(map(abs,c.values()))<4