class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int((2*n+1/4)**0.5-0.5)