class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        a = []
        l = s[0]
        c = 0
        for i in s:
            if i != l:
                a.append(c)
                c = 0
                l = i
            c += 1
        a.append(c)
        z = 0
        for i in range(1, len(a)):
            z += min(a[i], a[i - 1])
        return z