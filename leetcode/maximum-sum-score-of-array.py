class Solution:
    def maximumSumScore(self, a: List[int]) -> int:
        z = s = sum(a)
        t = 0
        for i in a:
            t += i
            z = max(z, max(s, t))
            s -= i
        return z