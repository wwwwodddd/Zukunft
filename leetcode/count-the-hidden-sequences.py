class Solution:
    def numberOfArrays(self, a: List[int], lower: int, upper: int) -> int:
        a = [0] + a
        for i in range(1, len(a)):
            a[i] += a[i - 1]
        return max(upper - lower - (max(a) - min(a)) + 1, 0)