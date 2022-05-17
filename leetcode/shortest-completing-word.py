class Solution:
    def shortestCompletingWord(self, s: str, a: List[str]) -> str:
        s = Counter(i.lower() for i in s if i.isalpha())
        return min([t for t in a if Counter(t) & s == s], key=len)