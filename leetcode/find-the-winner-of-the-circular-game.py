class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        z = 1
        for i in range(1, n + 1):
            z = (z + k) % i
        return z + 1