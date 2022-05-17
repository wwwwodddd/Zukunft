class Solution:
    def minimumRemoval(self, a: List[int]) -> int:
        a.sort()
        s = sum(a)
        t = 0
        z = s
        for i in range(len(a)):
            z = min(z, t + s - (len(a) - i) * a[i])
            s -= a[i]
            t += a[i]
        return z