class Solution:
    def closestDivisors(self, n: int) -> List[int]:
        return min(self.zuo(n + 1), self.zuo(n + 2))[1]
    def zuo(self, n):
        i = 1
        zd = n - 1
        zi = 1
        while i * i <= n:
            if n % i == 0:
                if zd > n // i - i:
                    zd = n // i - i
                    zi = i
            i += 1
        return zd, [zi, n // zi]