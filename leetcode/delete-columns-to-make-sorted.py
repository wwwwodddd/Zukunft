class Solution:
    def minDeletionSize(self, a: List[str]) -> int:
        return sum(sorted(b)!=list(b) for b in zip(*a))