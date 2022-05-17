class Solution:
    def largestCombination(self, a: List[int]) -> int:
        return max(sum(i >> j & 1 for i in a) for j in range(30))