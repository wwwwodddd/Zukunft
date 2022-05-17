class Solution:
    def sampleStats(self, c: List[int]) -> List[float]:
        mn = None
        mx = None
        avg = 0
        cnt = 0
        mode = 0
        for i in range(len(c)):
            avg += i * c[i]
            cnt += c[i]
            if c[i]:
                if mn == None:
                    mn = i
                mx = i
            if c[mode] < c[i]:
                mode = i
        c1 = (cnt + 1) // 2
        c2 = (cnt + 2) // 2
        m1 = 0
        m2 = 0
        for i in range(len(c)):
            c1 -= c[i]
            if c1 <= 0:
                m1 = i
                break
        for i in range(len(c)):
            c2 -= c[i]
            if c2 <= 0:
                m2 = i
                break
        return [mn, mx, avg / cnt, (m1 + m2) / 2, mode]