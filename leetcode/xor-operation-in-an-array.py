class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        z = 0
        for i in range(n):
            z ^= start + 2 * i
        return z