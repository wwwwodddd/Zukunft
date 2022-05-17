class Solution:
    def reachNumber(self, n: int) -> int:
        n = abs(n)
        s = 0
        i = 0
        while s < n or s % 2 != n % 2:
            i += 1
            s += i
        return i