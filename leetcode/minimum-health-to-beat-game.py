class Solution:
    def minimumHealth(self, a: List[int], m: int) -> int:
        return sum(a) - min(max(a), m) + 1