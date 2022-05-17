class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        c = Counter(s)
        return sum(c[i]%2 for i in c) <= k <= len(s)