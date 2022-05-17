class Solution:
    def largestInteger(self, s: int) -> int:
        s = str(s)
        a = []
        b = []
        for i in s:
            if int(i) % 2:
                a.append(i)
            else:
                b.append(i)
        z = ''
        a.sort(reverse=True)
        b.sort(reverse=True)
        ai = 0
        bi = 0
        for i in s:
            if int(i) % 2:
                z += a[ai]
                ai += 1
            else:
                z += b[bi]
                bi += 1
        return int(z)