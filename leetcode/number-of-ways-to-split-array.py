class Solution:
    def waysToSplitArray(self, a: List[int]) -> int:
        s = 0
        t = sum(a)
        z = 0
        for i in a[:-1]:
            s += i
            t -= i
            if s >= t:
                z += 1
        return z