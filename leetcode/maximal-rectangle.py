class Solution:
    def maximalRectangle(self, b: List[List[str]]) -> int:
        n = len(b)
        m = len(b[0])
        f = [0] * m
        def suan(a):
            s = []
            z = 0
            def push(x, y):
                nonlocal z
                w = 0
                while len(s) and s[-1][0] >= x:
                    w += s[-1][1]
                    z = max(z, s[-1][0] * w)
                    s.pop()
                s.append((x, w + y))
            for i in a:
                push(i, 1)
            push(0, 0)
            return z
        r = 0
        for i in range(n):
            for j in range(m):
                if b[i][j] == '1':
                    f[j] += 1
                else:
                    f[j] = 0
            r = max(r, suan(f))
        return r