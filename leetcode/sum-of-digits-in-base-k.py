class Solution:
    def sumBase(self, n: int, k: int) -> int:
        s = 0
        while n > 0:
            s += n % k
            n //= k
        return s