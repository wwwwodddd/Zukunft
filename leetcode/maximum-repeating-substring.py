class Solution:
    def maxRepeating(self, s: str, t: str) -> int:
        z = len(s)
        while z * t not in s:
            z -= 1
        return z