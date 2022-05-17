class Solution:
    def maximumDifference(self, a: List[int]) -> int:
        z = -1
        n = len(a)
        for j in range(n):
            for i in range(j):
                if a[i] < a[j]:
                    z = max(z, a[j] - a[i])
        return z