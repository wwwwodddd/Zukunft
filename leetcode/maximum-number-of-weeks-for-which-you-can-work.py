class Solution:
    def numberOfWeeks(self, a: List[int]) -> int:
        return min(sum(a), (sum(a) - max(a)) * 2 + 1)