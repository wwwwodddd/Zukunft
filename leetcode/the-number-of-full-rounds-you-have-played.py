class Solution:
    def numberOfRounds(self, a: str, b: str) -> int:
        s = int(a[:2]) * 60 + int(a[3:])
        t = int(b[:2]) * 60 + int(b[3:])
        if t < s:
            t += 1440
        return max(t // 15 - (s + 14) // 15, 0)