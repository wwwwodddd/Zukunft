class Solution:
    def sumSubarrayMins(self, a: List[int]) -> int:
        s = [(0, 0)]
        t = 0
        z = 0
        for i in range(len(a)):
            c = 1
            while a[i] <= s[-1][0]:
                c += s[-1][1]
                t -= s[-1][1] * s[-1][0]
                s.pop()
            t += a[i] * c
            s.append((a[i], c))
            z += t
        return z % 1000000007