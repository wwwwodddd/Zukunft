class Solution:
    @cache
    def minDays(self, n: int) -> int:
        if n < 2:
            return n
        return min(self.minDays(n // 2) + n % 2, self.minDays(n // 3) + n % 3) + 1