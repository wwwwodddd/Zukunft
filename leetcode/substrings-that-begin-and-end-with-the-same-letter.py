class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        c = Counter()
        z = 0
        for i in s:
            c[i] += 1
            z += c[i]
        return z