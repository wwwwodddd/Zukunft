class Solution:
    def validSquare(self, a: List[int], b: List[int], c: List[int], d: List[int]) -> bool:
        a, b, c, d = sorted([a, b, c, d])
        def D(a, b):
            return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2
        return a != d and D(a, b) == D(a, c) == D(b, d) == D(c, d) and D(a, d) == D(b, c)