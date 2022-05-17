class Solution:
    def maximumSubsequenceCount(self, s: str, t: str) -> int:
        x = y = z = 0
        for i in s:
            if i == t[1]:
                z += x
                y += 1
            if i == t[0]:
                x += 1
        return z + max(x, y)