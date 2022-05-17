class Solution:
    def countPairs(self, a: List[int]) -> int:
        c = Counter(a)
        b = 1
        z = 0
        for i in sorted(c):
            while b < i:
                b *= 2
            if b == i:
                z += (c[i] - 1) * c[i] // 2
            if i > b - i:
                z += c[b - i] * c[i]
        return z % 1000000007