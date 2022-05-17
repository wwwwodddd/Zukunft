class Solution:
    def minimumDeletions(self, a: List[int]) -> int:
        b = sorted([-1, a.index(min(a)), a.index(max(a)), len(a)])
        return len(a) - max(b[1] - b[0] - 1, b[2] - b[1] - 1, b[3] - b[2] - 1)