class Solution:
    def getMinimumTime(self, b: List[int], a: List[List[int]], l: int) -> int:
        z = 0
        for x, y in a:
            z += (y + l - 1) // l * b[x]
        return z