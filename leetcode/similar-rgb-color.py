class Solution:
    def similarRGB(self, d: str) -> str:
        a = int(d[1:3], 16)
        b = int(d[3:5], 16)
        c = int(d[5:7], 16)
        mn = 10000
        ans = ''
        for x in range(0, 256, 17):
            for y in range(0, 256, 17):
                for z in range(0, 256, 17):
                    f = (a - x) * (a - x) + (b - y) * (b - y) + (c - z) * (c - z)
                    if mn > f:
                        mn = f
                        ans = '#%02x%02x%02x' % (x, y, z)
        return ans