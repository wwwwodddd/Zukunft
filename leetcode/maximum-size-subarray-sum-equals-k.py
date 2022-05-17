class Solution:
    def maxSubArrayLen(self, a: List[int], k: int) -> int:
        g = {0 : -1}
        s = 0
        z = 0
        for i in range(len(a)):
            s += a[i]
            if s - k in g:
                z = max(z, i - g[s - k])
            if s not in g:
                g[s] = i
        return z