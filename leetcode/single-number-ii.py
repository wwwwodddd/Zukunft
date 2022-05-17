class Solution:
    def singleNumber(self, a: List[int]) -> int:
        x, y, z = -1, 0, 0
        for i in a:
            x, y, z = (x & ~i | z & i), (y & ~i | x & i), (z & ~i | y & i)
        return y