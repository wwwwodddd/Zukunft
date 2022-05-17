class Solution:
    def sortString(self, s: str) -> str:
        c = Counter(s)
        z = ''
        while len(z) < len(s):
            for i in sorted(c):
                if c[i] > 0:
                    z += i
                    c[i] -= 1
            for i in sorted(c)[::-1]:
                if c[i] > 0:
                    z += i
                    c[i] -= 1
        return z