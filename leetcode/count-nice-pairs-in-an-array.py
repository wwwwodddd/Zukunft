class Solution:
    def countNicePairs(self, a: List[int]) -> int:
        g = Counter()
        z = 0
        for i in a:
            x = i - int(str(i)[::-1])
            z += g[x]
            g[x] += 1
        return z % 1000000007