class Solution:
    def earliestFullBloom(self, a: List[int], b: List[int]) -> int:
        c = sorted(zip(b, a), reverse=True)
        z = s = 0
        for x, y in c:
            s += y
            z = max(z, s + x)
        return z