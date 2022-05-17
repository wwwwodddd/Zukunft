class Solution:
    def canBeEqual(self, a: List[int], b: List[int]) -> bool:
        return sorted(a) == sorted(b)