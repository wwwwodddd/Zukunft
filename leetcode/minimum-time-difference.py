class Solution:
    def findMinDifference(self, a: List[str]) -> int:
        b = []
        for i in a:
            h, m = map(int, i.split(':'))
            b.append(h * 60 + m)
        b.sort()
        z = 1440 + b[0] - b[-1]
        for x, y in zip(b, b[1:]):
            z = min(z, y - x)
        return z