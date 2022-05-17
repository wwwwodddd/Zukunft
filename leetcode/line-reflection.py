class Solution:
    def isReflected(self, a: List[List[int]]) -> bool:
        s = set((x, y) for x, y in a)
        l = min(x for x, y in s) + max(x for x, y in s)
        t = set((l - x, y) for x, y in s)
        return s == t