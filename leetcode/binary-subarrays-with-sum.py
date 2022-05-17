class Solution:
    def numSubarraysWithSum(self, a: List[int], t: int) -> int:
        g = Counter()
        g[0] = 1
        s = 0
        z = 0
        for i in a:
            s += i
            z += g[s - t]
            g[s] += 1
        return z