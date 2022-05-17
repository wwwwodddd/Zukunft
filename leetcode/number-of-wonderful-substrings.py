class Solution:
    def wonderfulSubstrings(self, s: str) -> int:
        c = [0 for i in range(1024)]
        z = b = 0
        c[b] += 1
        for i in s:
            b ^= 1 << ord(i) - 97
            z += c[b]
            for j in range(10):
                z += c[b ^ 1 << j]
            c[b] += 1
        return z