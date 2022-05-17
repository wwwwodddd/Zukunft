class Solution:
    def maxCoins(self, a: List[int]) -> int:
        return sum(sorted(a)[len(a)//3::2])