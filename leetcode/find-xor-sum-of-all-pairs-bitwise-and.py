class Solution:
    def getXORSum(self, a: List[int], b: List[int]) -> int:
        x = 0
        for i in a:
            x ^= i
        y = 0
        for i in b:
            y ^= i
        return x & y