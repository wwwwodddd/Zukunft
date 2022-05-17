class Solution:
    def closeStrings(self, s: str, t: str) -> bool:
        return set(s)==set(t) and sorted(Counter(s).values())==sorted(Counter(t).values())