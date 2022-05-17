class Solution:
    def numPairsDivisibleBy60(self, a: List[int]) -> int:
        d = [0 for i in range(60)]
        for i in a:
            d[i % 60] += 1
        z = d[0] * (d[0] - 1) // 2 + d[30] * (d[30] - 1) // 2
        for i in range(1, 30):
            z += d[i] * d[60 - i]
        return z