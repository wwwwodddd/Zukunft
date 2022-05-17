class Solution:
    def lastRemaining(self, n: int) -> int:
        def gan(n):
            if n == 1:
                return 1
            return n - n % 2 + 2 - 2 * gan(n // 2)
        return gan(n)