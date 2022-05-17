class Solution:
    def arrayPairSum(self, a: List[int]) -> int:
        return sum(sorted(a)[::2])