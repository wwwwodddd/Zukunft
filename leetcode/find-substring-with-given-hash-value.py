class Solution:
    def subStrHash(self, s: str, p: int, mod: int, k: int, hsh: int) -> str:
        h = 0
        for i in range(k):
            h = (h + (ord(s[-k + i]) - 96) * pow(p, i, mod)) % mod
        z = -1
        if h == hsh:
            z = len(s) - k
        for i in range(len(s) - k)[::-1]:
            h = (h * p + (ord(s[i]) - 96) - (ord(s[i + k]) - 96) * pow(p, k, mod)) % mod
            if h == hsh:
                z = i
        return s[z : z + k]
                