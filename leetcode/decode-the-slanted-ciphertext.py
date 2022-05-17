class Solution:
    def decodeCiphertext(self, s: str, n: int) -> str:
        m = len(s) // n
        z = ''
        for i in range(m):
            for j in range(i, len(s), m + 1):
                z += s[j]
        return z.rstrip()