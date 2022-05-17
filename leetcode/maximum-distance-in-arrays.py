class Solution:
    def maxDistance(self, a: List[List[int]]) -> int:
        x, y = 1e9, -1e9
        z = 0
        for b in a:
            z = max(z, y - b[0], b[-1] - x)
            x = min(x, b[0])
            y = max(y, b[-1])
        return z