class Solution:
    def numTimesAllBlue(self, a: List[int]) -> int:
        t = len(a)
        z = 0
        for i in range(len(a))[::-1]:
            t = min(t, a[i])
            if t == i + 1:
                z += 1
        return z