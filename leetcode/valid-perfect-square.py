class Solution:
    def isPerfectSquare(self, n: int) -> bool:
        i = n
        while i * i > n:
            i = (i + n // i) // 2
        return i * i == n