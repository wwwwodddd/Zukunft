class Solution:
    def numberOfArithmeticSlices(self, a: List[int]) -> int:
        f = [Counter()for i in a]
        z = 0
        for i in range(len(a)):
            for j in range(i):
                d = a[i] - a[j]
                z += f[j][d]
                f[i][d] += f[j][d] + 1
        return z