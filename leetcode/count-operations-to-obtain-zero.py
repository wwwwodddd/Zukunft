class Solution:
    def countOperations(self, x: int, y: int) -> int:
        z = 0
        while x > 0 and y > 0:
            z += x // y
            x, y = y, x % y
        return z