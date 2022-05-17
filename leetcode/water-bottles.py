class Solution:
    def numWaterBottles(self, n: int, m: int) -> int:
        return n+(n-1)//(m-1)