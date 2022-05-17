class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        p = 1000000007
        n += k - 1
        x = 1
        y = 1
        for i in range(2 * k):
            x = x * (n - i) % p
            y = y * (i + 1) % p
        return x * pow(y, p - 2, p) % p