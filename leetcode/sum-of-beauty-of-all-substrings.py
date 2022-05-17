class Solution:
    def beautySum(self, s: str) -> int:
        z = 0
        for i in range(len(s)):
            c = Counter()
            for j in s[i:]:
                c[j] += 1
                z += max(c.values()) - min(c.values())
        return z