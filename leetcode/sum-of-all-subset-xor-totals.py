class Solution:
    def subsetXORSum(self, a: List[int]) -> int:
        z = 0
        for i in a:
            z |= i
        return z * 2 ** (len(a) - 1)