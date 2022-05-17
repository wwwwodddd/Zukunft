class Solution:
    def interchangeableRectangles(self, a: List[List[int]]) -> int:
        c = Counter()
        z = 0
        for x, y in a:
            g = gcd(x, y)
            x //= g
            y //= g
            z += c[x, y]
            c[x, y] += 1
        return z