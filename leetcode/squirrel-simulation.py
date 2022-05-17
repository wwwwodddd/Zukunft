class Solution:
    def minDistance(self, height: int, width: int, t: List[int], s: List[int], nuts: List[List[int]]) -> int:
        z = 0
        for x, y in nuts:
            z += 2 * (abs(x - t[0]) + abs(y - t[1]))
        return z - max((abs(x - t[0]) + abs(y - t[1])) - (abs(x - s[0]) + abs(y - s[1])) for x, y in nuts)