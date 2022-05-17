class Solution:
    def numSplits(self, s: str) -> int:
        a = [0 for i in range(256)]
        b = [0 for i in range(256)]
        c = 0
        d = 0
        z = 0
        for i in s:
            if b[ord(i)] == 0:
                d += 1
            b[ord(i)] += 1
        for i in s:
            b[ord(i)] -= 1
            if b[ord(i)] == 0:
                d -= 1
            if a[ord(i)] == 0:
                c += 1
            a[ord(i)] += 1
            if c == d:
                z += 1
        return z
            