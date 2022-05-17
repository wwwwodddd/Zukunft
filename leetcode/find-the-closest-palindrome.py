class Solution:
    def nearestPalindromic(self, s: str) -> str:
        n = int(s)
        z = 0
        def xin(x):
            nonlocal z
            if x == n:
                return
            if abs(z - n) > abs(x - n) or abs(z - n) == abs(x - n) and z > x:
                z = x
        for i in range(1, 19):
            xin(10 ** i + 1)
            xin(10 ** i - 1)
        s = s[:(len(s) + 1) // 2]
        for x in range(max(1, int(s) - 10), int(s) + 10):
            xin(int(str(x) + str(x)[::-1]))
            xin(int(str(x)[:-1] + str(x)[::-1]))
        return str(z)