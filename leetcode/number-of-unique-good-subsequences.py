class Solution:
    def numberOfUniqueGoodSubsequences(self, s: str) -> int:
        p = 1000000007
        f = [0, 0]
        for i in s[::-1]:
            f[int(i)] = (sum(f) + 1) % p
        return (f[1] + ('0' in s)) % p