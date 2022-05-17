class Solution:
    def minSubarray(self, a: List[int], p: int) -> int:
        d = sum(a) % p
        z = len(a)
        s = 0
        g = {0: -1}
        for i in range(len(a)):
            s = (s + a[i]) % p
            g[s] = i
            if (s-d)%p in g:
                z = min(z, i-g[(s-d)%p])
        if z == len(a):
            z = -1
        return z