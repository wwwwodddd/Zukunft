class Solution:
    def countGoodNumbers(self, n: int) -> int:
        return pow(20, n // 2, 1000000007) * 5 ** (n % 2) % 1000000007