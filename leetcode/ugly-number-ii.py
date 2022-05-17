class Solution:
    def nthUglyNumber(self, n: int) -> int:
        a = [1]
        p2 = p3 = p5 = 0
        for i in range(n):
            r2 = a[p2] * 2
            r3 = a[p3] * 3
            r5 = a[p5] * 5
            r = min(r2, r3, r5)
            a.append(r)
            if r == r2:
                p2 += 1
            if r == r3:
                p3 += 1
            if r == r5:
                p5 += 1
        return a[n - 1]