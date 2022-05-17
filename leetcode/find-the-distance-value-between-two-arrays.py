class Solution:
    def findTheDistanceValue(self, a: List[int], b: List[int], d: int) -> int:
        a = sorted(a)
        b = [-2000] + sorted(b) + [2000]
        j = 0
        z = 0
        for i in a:
            while b[j + 1] < i:
                j += 1
            if b[j] < i - d and i + d < b[j + 1]:
                z += 1
        return z