class Solution:
    def maxSizeSlices(self, a: List[int]) -> int:
        n = len(a)
        z = 0
        for i in range(n//3):
            mx = max(a)
            z += mx
            j = a.index(mx)
            a = a[j:] + a[:j]
            a[0] = a[1] + a[-1] - a[0]
            del a[1]
            del a[-1]
        return z