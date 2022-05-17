class Solution:
    def convertTime(self, a: str, b: str) -> int:
        z = 0
        e = (int(b[0:2]) - int(a[0:2])) * 60 + int(b[3:5]) - int(a[3:5])
        for i in [60, 15, 5, 1]:
            z += e // i
            e %= i
        return z