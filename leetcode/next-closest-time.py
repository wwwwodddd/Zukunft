class Solution:
    def nextClosestTime(self, t: str) -> str:
        s = {t[0], t[1], t[3], t[4]}
        x = int(t[:2]) * 60 + int(t[3:])
        while True:
            x = (x + 1) % 1440
            r = '%02d:%02d' % (x // 60, x % 60)
            a = {r[0], r[1], r[3], r[4]}
            if a <= s:
                return r